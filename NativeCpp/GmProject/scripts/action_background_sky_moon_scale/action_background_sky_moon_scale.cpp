#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_sky_moon_scale(BackgroundActionContext& context, double value, double add)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_sky_moon_scale", "BG_SKY_MOON_SCALE", value / 100.0, add))
        return;
    if (context.historyUndo || context.historyRedo)
        value *= 100.0;
    assignBackgroundScaledValue(context, "action_background_sky_moon_scale", "background_sky_moon_scale", value, add, 100.0);
}
}
