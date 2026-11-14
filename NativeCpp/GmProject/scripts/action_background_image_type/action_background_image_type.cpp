#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_image_type(BackgroundActionContext& context, const QVariant& value)
{
    assignBackgroundValue(context, "action_background_image_type", "background_image_type", value, false);
}
}
