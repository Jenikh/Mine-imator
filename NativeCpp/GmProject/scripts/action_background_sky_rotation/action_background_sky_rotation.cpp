#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_sky_rotation(BackgroundActionContext& context, double value, double add)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_sky_rotation", "BG_SKY_ROTATION", value, add))
        return;
    assignBackgroundNumericValue(context, "action_background_sky_rotation", "background_sky_rotation", value, add);
}
}
