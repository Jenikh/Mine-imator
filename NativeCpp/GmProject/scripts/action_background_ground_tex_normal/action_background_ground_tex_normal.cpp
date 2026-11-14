#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_ground_tex_normal(BackgroundActionContext& context, BackgroundResourceRequest request)
{
    QVariant resource;
    if (!beginBackgroundResourceEdit(context, "action_background_ground_tex_normal", "background_ground_tex_normal",
                                     request, BackgroundResourceType::BlockSheet, true, resource))
        return;
    if (context.releaseResource)
        context.releaseResource(context.values.value("background_ground_tex_normal"));
    context.values.insert("background_ground_tex_normal", resource);
    if (context.retainResource)
        context.retainResource(resource);
    if (context.updateGroundTexturesNormal) context.updateGroundTexturesNormal();
}
}
