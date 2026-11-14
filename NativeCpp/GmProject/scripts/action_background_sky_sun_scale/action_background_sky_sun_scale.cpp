#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_sky_sun_scale(BackgroundActionContext& context, double value, double add)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_sky_sun_scale", "BG_SKY_SUN_SCALE", value / 100.0, add))
        return;
    if (context.historyUndo || context.historyRedo)
        value *= 100.0;
    assignBackgroundScaledValue(context, "action_background_sky_sun_scale", "background_sky_sun_scale", value, add, 100.0);
}
}
