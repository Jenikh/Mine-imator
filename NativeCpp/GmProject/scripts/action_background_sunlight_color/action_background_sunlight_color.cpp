#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_sunlight_color(BackgroundActionContext& context, const QVariant& color)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_sunlight_color", "BG_SUNLIGHT_COLOR", color, 0.0))
        return;
    assignBackgroundValue(context, "action_background_sunlight_color", "background_sunlight_color", color, true);
}
}
