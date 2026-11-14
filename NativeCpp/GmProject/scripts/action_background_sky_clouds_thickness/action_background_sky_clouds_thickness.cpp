#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_sky_clouds_thickness(BackgroundActionContext& context, double value, double add)
{
    assignBackgroundNumericValue(context, "action_background_sky_clouds_thickness", "background_sky_clouds_thickness", value, add);
    if (context.updateClouds) context.updateClouds();
}
}
