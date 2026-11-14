#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_leaves_mangrove_color(BackgroundActionContext& context, const QVariant& value)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_leaves_mangrove_color", "BG_LEAVES_MANGROVE_COLOR", value, 0.0))
        return;
    assignBackgroundValue(context, "action_background_leaves_mangrove_color", "background_leaves_mangrove_color", value, true);
    if (context.refreshResourceColors) context.refreshResourceColors();
    if (context.markLibraryPreviewDirty) context.markLibraryPreviewDirty();
}
}
