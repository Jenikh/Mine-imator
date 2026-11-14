#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_sky_clouds_color(BackgroundActionContext& context, const QVariant& color)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_sky_clouds_color", "BG_SKY_CLOUDS_COLOR", color, 0.0))
        return;
    assignBackgroundValue(context, "action_background_sky_clouds_color", "background_sky_clouds_color", color, true);
}
}
