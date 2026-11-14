#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_sky_sun_angle(BackgroundActionContext& context, double value, double add)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_sky_sun_angle", "BG_SKY_SUN_ANGLE", value, add))
        return;
    assignBackgroundNumericValue(context, "action_background_sky_sun_angle", "background_sky_sun_angle", value, add);
}
}
