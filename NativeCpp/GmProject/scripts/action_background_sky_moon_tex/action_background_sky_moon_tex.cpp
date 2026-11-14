#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_sky_moon_tex(BackgroundActionContext& context, BackgroundResourceRequest request)
{
    QVariant resource;
    if (!beginBackgroundResourceEdit(context, "action_background_sky_moon_tex", "background_sky_moon_tex",
                                     request, BackgroundResourceType::Texture, true, resource))
        return;
    if (context.releaseResource)
        context.releaseResource(context.values.value("background_sky_moon_tex"));
    context.values.insert("background_sky_moon_tex", resource);
    if (context.retainResource)
        context.retainResource(resource);
}
}
