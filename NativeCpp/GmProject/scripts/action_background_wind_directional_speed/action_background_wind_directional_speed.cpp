#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_wind_directional_speed(BackgroundActionContext& context, double value, double add)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_wind_directional_speed", "BG_WIND_DIRECTIONAL_SPEED", value / 100.0, add))
        return;
    if (context.historyUndo || context.historyRedo)
        value *= 100.0;
    assignBackgroundScaledValue(context, "action_background_wind_directional_speed", "background_wind_directional_speed", value, add, 100.0);
}
}
