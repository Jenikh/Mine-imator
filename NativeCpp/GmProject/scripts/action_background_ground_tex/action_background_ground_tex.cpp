#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_ground_tex(BackgroundActionContext& context, BackgroundResourceRequest request)
{
    QVariant resource;
    if (!beginBackgroundResourceEdit(context, "action_background_ground_tex", "background_ground_tex",
                                     request, BackgroundResourceType::BlockSheet, true, resource))
        return;
    if (context.releaseResource)
        context.releaseResource(context.values.value("background_ground_tex"));
    context.values.insert("background_ground_tex", resource);
    if (context.retainResource)
        context.retainResource(resource);
    if (context.updateGroundTextures) context.updateGroundTextures();
}
}
