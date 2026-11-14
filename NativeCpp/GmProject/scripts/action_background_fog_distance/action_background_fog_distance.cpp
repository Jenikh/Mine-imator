#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_fog_distance(BackgroundActionContext& context, double value, double add)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_fog_distance",
                          "BG_FOG_DISTANCE", value, add))
        return;
    assignBackgroundNumericValue(context, "action_background_fog_distance",
                                 "background_fog_distance", value, add);
}
}
