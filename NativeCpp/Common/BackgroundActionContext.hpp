#pragma once

#include <QVariant>
#include <QVariantMap>
#include <QString>
#include <functional>

namespace MineImator::Native
{
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
        std::function<void(const QString&, const QVariant&, const QVariant&, bool)> recordHistory;
    };

    inline bool beginTimelineEdit(BackgroundActionContext& context,
                                  const QString& action,
                                  const QString& timelineValue,
                                  const QVariant& value,
                                  double add)
    {
        if (!context.selectBackground || !context.selectBackground())
            return false;

        if (context.timelineBegin)
            context.timelineBegin(action, true);
        if (context.timelineSet)
            context.timelineSet(timelineValue, value, add);
        if (context.timelineDone)
            context.timelineDone();
        return true;
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
}
