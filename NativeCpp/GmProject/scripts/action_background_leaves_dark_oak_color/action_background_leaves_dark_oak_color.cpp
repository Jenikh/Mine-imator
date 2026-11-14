#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_leaves_dark_oak_color(BackgroundActionContext& context, const QVariant& value)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_leaves_dark_oak_color", "BG_LEAVES_DARK_OAK_COLOR", value, 0.0))
        return;
    assignBackgroundValue(context, "action_background_leaves_dark_oak_color", "background_leaves_dark_oak_color", value, true);
    if (context.refreshResourceColors) context.refreshResourceColors();
    if (context.markLibraryPreviewDirty) context.markLibraryPreviewDirty();
}
}
