#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_image_box_mapped(BackgroundActionContext& context, const QVariant& mapped)
{
    assignBackgroundValue(context, "action_background_image_box_mapped",
                          "background_image_box_mapped", mapped, false);
}
}
