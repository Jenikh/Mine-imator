#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_sky_clouds_mode(BackgroundActionContext& context, const QVariant& value)
{
    assignBackgroundValue(context, "action_background_sky_clouds_mode", "background_sky_clouds_mode", value, false);
    if (context.updateClouds) context.updateClouds();
}
}
