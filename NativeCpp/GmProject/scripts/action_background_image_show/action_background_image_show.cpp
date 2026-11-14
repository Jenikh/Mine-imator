#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_image_show(BackgroundActionContext& context, const QVariant& value)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_image_show", "BG_IMAGE_SHOW", value, 0.0))
        return;
    assignBackgroundValue(context, "action_background_image_show", "background_image_show", value, false);
}
}
