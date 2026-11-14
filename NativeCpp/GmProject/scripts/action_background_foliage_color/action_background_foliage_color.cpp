#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_foliage_color(BackgroundActionContext& context, const QVariant& color)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_foliage_color",
                          "BG_FOLIAGE_COLOR", color, 0.0))
        return;
    assignBackgroundValue(context, "action_background_foliage_color",
                          "background_foliage_color", color, true);
    if (context.refreshResourceColors) context.refreshResourceColors();
    if (context.markLibraryPreviewDirty) context.markLibraryPreviewDirty();
}
}
