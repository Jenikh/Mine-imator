#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_image_stretch(BackgroundActionContext& context, const QVariant& value)
{
    assignBackgroundValue(context, "action_background_image_stretch", "background_image_stretch", value, false);
}
}
