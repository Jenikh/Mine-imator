#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_wind_direction(BackgroundActionContext& context, double value, double add)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_wind_direction", "BG_WIND_DIRECTION", value, add))
        return;
    assignBackgroundNumericValue(context, "action_background_wind_direction", "background_wind_direction", value, add);
}
}
