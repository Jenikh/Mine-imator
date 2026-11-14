#include "../../../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_fog_size(BackgroundActionContext& context, double value, double add)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_fog_size",
                          "BG_FOG_SIZE", value, add != 1.0))
        return;
    assignBackgroundNumericValue(context, "action_background_fog_size",
                                 "background_fog_size", value, add);
}
}
