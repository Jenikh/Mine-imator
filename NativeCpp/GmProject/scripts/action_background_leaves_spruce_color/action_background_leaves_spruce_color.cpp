#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_leaves_spruce_color(BackgroundActionContext& context, const QVariant& color)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_leaves_spruce_color", "BG_LEAVES_SPRUCE_COLOR", color, 0.0))
        return;
    assignBackgroundValue(context, "action_background_leaves_spruce_color", "background_leaves_spruce_color", color, true);
    if (context.refreshResourceColors) context.refreshResourceColors();
    if (context.markLibraryPreviewDirty) context.markLibraryPreviewDirty();
}
}
