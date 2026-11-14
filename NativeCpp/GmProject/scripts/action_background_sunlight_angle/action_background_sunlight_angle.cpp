#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_sunlight_angle(BackgroundActionContext& context, double value, double add)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_sunlight_angle", "BG_SUNLIGHT_ANGLE", value, add))
        return;
    assignBackgroundNumericValue(context, "action_background_sunlight_angle", "background_sunlight_angle", value, add);
}
}
