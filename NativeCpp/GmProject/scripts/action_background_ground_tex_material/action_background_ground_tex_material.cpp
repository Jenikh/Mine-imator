#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_ground_tex_material(BackgroundActionContext& context, BackgroundResourceRequest request)
{
    QVariant resource;
    if (!beginBackgroundResourceEdit(context, "action_background_ground_tex_material", "background_ground_tex_material",
                                     request, BackgroundResourceType::BlockSheet, true, resource))
        return;
    if (context.releaseResource)
        context.releaseResource(context.values.value("background_ground_tex_material"));
    context.values.insert("background_ground_tex_material", resource);
    if (context.retainResource)
        context.retainResource(resource);
    if (context.updateGroundTexturesMaterial) context.updateGroundTexturesMaterial();
}
}
