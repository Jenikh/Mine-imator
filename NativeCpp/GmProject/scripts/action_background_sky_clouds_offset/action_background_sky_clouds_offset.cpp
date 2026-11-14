#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_sky_clouds_offset(BackgroundActionContext& context, double value, double add)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_sky_clouds_offset", "BG_SKY_CLOUDS_OFFSET", value, add))
        return;
    assignBackgroundNumericValue(context, "action_background_sky_clouds_offset", "background_sky_clouds_offset", value, add);
}
}
