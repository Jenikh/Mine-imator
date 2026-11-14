#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_image(BackgroundActionContext& context, BackgroundResourceRequest request)
{
    QVariant resource;
    if (!beginBackgroundResourceEdit(context, "action_background_image", "background_image",
                                     request, BackgroundResourceType::Texture, false, resource))
        return;
    if (!isNullResource(context.values.value("background_image")) &&
        context.releaseResource)
        context.releaseResource(context.values.value("background_image"));
    context.values.insert("background_image", resource);
    if (!isNullResource(resource) && context.retainResource)
        context.retainResource(resource);
}
}
