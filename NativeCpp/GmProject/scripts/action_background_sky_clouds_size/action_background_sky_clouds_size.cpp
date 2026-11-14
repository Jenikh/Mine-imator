#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_sky_clouds_size(BackgroundActionContext& context, double value, double add)
{
    assignBackgroundNumericValue(context, "action_background_sky_clouds_size", "background_sky_clouds_size", value, add);
    if (context.updateClouds) context.updateClouds();
}
}
