#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_grass_color(BackgroundActionContext& context, const QVariant& color)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_grass_color",
                          "BG_GRASS_COLOR", color, 0.0))
        return;
    assignBackgroundValue(context, "action_background_grass_color",
                          "background_grass_color", color, true);
    if (context.refreshResourceColors) context.refreshResourceColors();
    if (context.markLibraryPreviewDirty) context.markLibraryPreviewDirty();
}
}
