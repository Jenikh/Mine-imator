#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_sky_color(BackgroundActionContext& context, const QVariant& color)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_sky_color", "BG_SKY_COLOR", color, 0.0))
        return;
    assignBackgroundValue(context, "action_background_sky_color", "background_sky_color", color, true);
}
}
