#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_leaves_acacia_color(BackgroundActionContext& context, const QVariant& value)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_leaves_acacia_color", "BG_LEAVES_ACACIA_COLOR", value, 0.0))
        return;
    assignBackgroundValue(context, "action_background_leaves_acacia_color", "background_leaves_acacia_color", value, true);
    if (context.refreshResourceColors) context.refreshResourceColors();
    if (context.markLibraryPreviewDirty) context.markLibraryPreviewDirty();
}
}
