#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_ground_show(BackgroundActionContext& context, const QVariant& show)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_ground_show",
                          "BG_GROUND_SHOW", show, 0.0))
        return;
    assignBackgroundValue(context, "action_background_ground_show",
                          "background_ground_show", show, false);
}
}
