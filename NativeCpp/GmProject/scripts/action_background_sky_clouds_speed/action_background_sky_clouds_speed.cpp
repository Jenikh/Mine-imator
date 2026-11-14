#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_sky_clouds_speed(BackgroundActionContext& context, double value, double add)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_sky_clouds_speed", "BG_SKY_CLOUDS_SPEED", value / 100.0, add))
        return;
    if (context.historyUndo || context.historyRedo)
        value *= 100.0;
    assignBackgroundScaledValue(context, "action_background_sky_clouds_speed", "background_sky_clouds_speed", value, add, 100.0);
}
}
