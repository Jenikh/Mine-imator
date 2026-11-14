#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_fog_height(BackgroundActionContext& context, double value, double add)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_fog_height",
                          "BG_FOG_HEIGHT", value, add))
        return;
    assignBackgroundNumericValue(context, "action_background_fog_height",
                                 "background_fog_height", value, add);
}
}
