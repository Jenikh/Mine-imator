#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_sky_clouds_height(BackgroundActionContext& context, double value, double add)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_sky_clouds_height", "BG_SKY_CLOUDS_HEIGHT", value, add))
        return;
    assignBackgroundNumericValue(context, "action_background_sky_clouds_height", "background_sky_clouds_height", value, add);
}
}
