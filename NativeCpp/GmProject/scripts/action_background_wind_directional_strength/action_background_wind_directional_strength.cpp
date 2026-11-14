#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_wind_directional_strength(BackgroundActionContext& context, double value, double add)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_wind_directional_strength", "BG_WIND_DIRECTIONAL_STRENGTH", value, add))
        return;
    assignBackgroundNumericValue(context, "action_background_wind_directional_strength", "background_wind_directional_strength", value, add);
}
}
