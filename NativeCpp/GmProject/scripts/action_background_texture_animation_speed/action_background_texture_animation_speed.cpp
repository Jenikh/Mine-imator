#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_texture_animation_speed(BackgroundActionContext& context, double value, double add)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_texture_animation_speed", "BG_TEXTURE_ANI_SPEED", value, add))
        return;
    assignBackgroundNumericValue(context, "action_background_texture_animation_speed", "background_texture_animation_speed", value, add);
}
}
