#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_image_rotation(BackgroundActionContext& context, double value, double add)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_image_rotation",
                          "BG_IMAGE_ROTATION", value, add))
        return;
    assignBackgroundNumericValue(context, "action_background_image_rotation",
                                 "background_image_rotation", value, add);
}
}
