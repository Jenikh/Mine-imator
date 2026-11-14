#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_sky_clouds_tex(BackgroundActionContext& context, BackgroundResourceRequest request)
{
    QVariant resource;
    if (!beginBackgroundResourceEdit(context, "action_background_sky_clouds_tex", "background_sky_clouds_tex",
                                     request, BackgroundResourceType::Texture, true, resource))
        return;
    if (context.releaseResource)
        context.releaseResource(context.values.value("background_sky_clouds_tex"));
    context.values.insert("background_sky_clouds_tex", resource);
    if (context.retainResource)
        context.retainResource(resource);
    if (context.updateClouds) context.updateClouds();
}
}
