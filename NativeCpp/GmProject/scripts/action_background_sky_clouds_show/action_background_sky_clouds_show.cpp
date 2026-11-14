#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_sky_clouds_show(BackgroundActionContext& context, const QVariant& value)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_sky_clouds_show", "BG_SKY_CLOUDS_SHOW", value, 0.0))
        return;
    assignBackgroundValue(context, "action_background_sky_clouds_show", "background_sky_clouds_show", value, false);
}
}
