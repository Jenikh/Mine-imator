#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_water_color(BackgroundActionContext& context, const QVariant& color)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_water_color", "BG_WATER_COLOR", color, 0.0))
        return;
    assignBackgroundValue(context, "action_background_water_color", "background_water_color", color, true);
    if (context.refreshResourceColors) context.refreshResourceColors();
    if (context.markLibraryPreviewDirty) context.markLibraryPreviewDirty();
}
}
