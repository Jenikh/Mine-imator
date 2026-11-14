#pragma once

#include <QVariant>
#include <QVariantMap>
#include <QString>
#include <functional>

namespace MineImator::Native
{
    // Resource kinds accepted by the background texture selectors.
    // Mirrors e_res_type for the subset reachable from background actions.
    enum class BackgroundResourceType
    {
        Texture,
        BlockSheet,
        Pack
    };

    // Argument of a background resource action. GameMaker passed an object
    // instance, null or e_option.BROWSE; the native API states that intent.
    struct BackgroundResourceRequest
    {
        enum class Kind
        {
            None,
            Existing,
            Browse
        };

        Kind kind = Kind::None;
        QVariant resource;

        static BackgroundResourceRequest none()
        {
            return {};
        }

        static BackgroundResourceRequest existing(const QVariant& resource)
        {
            BackgroundResourceRequest request;
            request.kind = Kind::Existing;
            request.resource = resource;
            return request;
        }

        static BackgroundResourceRequest browse()
        {
            BackgroundResourceRequest request;
            request.kind = Kind::Browse;
            return request;
        }
    };

    // Adapter boundary for native implementations of GameMaker background actions.
    // The application supplies timeline/history callbacks; actions own value semantics.
    struct BackgroundActionContext
    {
        QVariantMap values;
        bool historyUndo = false;
        bool historyRedo = false;

        std::function<bool()> selectBackground;
        std::function<void(const QString&, bool)> timelineBegin;
        std::function<void(const QString&, const QVariant&, double)> timelineSet;
        std::function<void()> timelineDone;
        std::function<void()> refreshResourceColors;
        std::function<void()> markLibraryPreviewDirty;
        std::function<void()> updateGroundTextures;
        std::function<void()> updateGroundTexturesMaterial;
        std::function<void()> updateGroundTexturesNormal;
        std::function<void()> updateClouds;
        std::function<void(const QString&, const QVariant&, const QVariant&, bool)> recordHistory;

        // Resource selection and lifetime. history_undo_res/history_redo_res,
        // file_dialog_open_image(_pack), file_exists_lib, new_res/res_load,
        // history_set_res and the obj_resource reference counters.
        std::function<QVariant()> undoResource;
        std::function<QVariant()> redoResource;
        std::function<QString(bool)> browseResourceFile;
        std::function<bool(const QString&)> libraryFileExists;
        std::function<QVariant(const QString&, BackgroundResourceType)> createResource;
        std::function<void(const QString&, const QString&, const QVariant&, const QVariant&)> recordResourceHistory;
        std::function<void(const QVariant&)> releaseResource;
        std::function<void(const QVariant&)> retainResource;

        // Biomes are resolved through obj_biome; group entries expand to their
        // first variant. Returns the argument unchanged when nothing matched.
        std::function<QString(const QVariant&)> resolveBiomeName;

        // action_background_image_save_map()
        std::function<QString(const QString&)> saveImageDialog;
        std::function<void(const QString&)> saveMapCubeImage;
    };

    inline bool beginTimelineEditWithHistory(BackgroundActionContext& context,
                                            const QString& action,
                                            const QString& timelineValue,
                                            const QVariant& value,
                                            double add,
                                            bool historyFlag)
    {
        if (!context.selectBackground || !context.selectBackground())
            return false;

        if (context.timelineBegin)
            context.timelineBegin(action, historyFlag);
        if (context.timelineSet)
            context.timelineSet(timelineValue, value, add);
        if (context.timelineDone)
            context.timelineDone();
        return true;
    }

    inline bool beginTimelineEdit(BackgroundActionContext& context,
                                  const QString& action,
                                  const QString& timelineValue,
                                  const QVariant& value,
                                  double add)
    {
        return beginTimelineEditWithHistory(context, action, timelineValue, value, add, true);
    }

    inline void assignBackgroundValue(BackgroundActionContext& context,
                                       const QString& action,
                                       const QString& key,
                                       const QVariant& value,
                                       bool historyFlag)
    {
        const QVariant previous = context.values.value(key);
        if (!context.historyUndo && !context.historyRedo && context.recordHistory)
            context.recordHistory(action, previous, value, historyFlag);
        context.values.insert(key, value);
    }

    inline void assignBackgroundNumericValue(BackgroundActionContext& context,
                                             const QString& action,
                                             const QString& key,
                                             double value,
                                             double add)
    {
        const double previous = context.values.value(key).toDouble();
        const double next = previous * add + value;
        if (!context.historyUndo && !context.historyRedo && context.recordHistory)
            context.recordHistory(action, previous, next, true);
        context.values.insert(key, next);
    }

    // Numeric actions whose public argument is scaled but whose stored and
    // timeline value is not (wind and sky speed/scale percentages).
    inline void assignBackgroundScaledValue(BackgroundActionContext& context,
                                           const QString& action,
                                           const QString& key,
                                           double value,
                                           double add,
                                           double divisor)
    {
        const double previous = context.values.value(key).toDouble();
        const double next = previous * add + value / divisor;
        if (!context.historyUndo && !context.historyRedo && context.recordHistory)
            context.recordHistory(action, previous, next, true);
        context.values.insert(key, next);
    }

    inline bool isNullResource(const QVariant& resource)
    {
        return !resource.isValid() || resource.isNull();
    }

    // Resolves the argument of a background resource action: replays the stored
    // save id while undoing/redoing, browses the library on request, and hands
    // the old/new pair to the history recorder. Returns false when the browse
    // dialog produced no usable file, matching the early `return 0`.
    inline bool beginBackgroundResourceEdit(BackgroundActionContext& context,
                                           const QString& action,
                                           const QString& key,
                                           BackgroundResourceRequest request,
                                           BackgroundResourceType type,
                                           bool imagePack,
                                           QVariant& resource)
    {
        if (context.historyUndo)
        {
            resource = context.undoResource ? context.undoResource() : QVariant();
            return true;
        }

        if (context.historyRedo)
        {
            resource = context.redoResource ? context.redoResource() : QVariant();
            return true;
        }

        QString filename;
        if (request.kind == BackgroundResourceRequest::Kind::Browse)
        {
            filename = context.browseResourceFile ? context.browseResourceFile(imagePack) : QString();
            if (!context.libraryFileExists || !context.libraryFileExists(filename))
                return false;
            resource = context.createResource ? context.createResource(filename, type) : QVariant();
        }
        else
            resource = request.resource;

        if (context.recordResourceHistory)
            context.recordResourceHistory(action, filename, context.values.value(key), resource);
        return true;
    }
}
