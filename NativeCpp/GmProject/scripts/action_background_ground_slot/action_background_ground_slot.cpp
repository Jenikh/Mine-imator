#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_ground_slot(BackgroundActionContext& context, const QVariant& slot)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_ground_slot",
                          "BG_GROUND_SLOT", slot, 0.0))
        return;
    assignBackgroundValue(context, "action_background_ground_slot",
                          "background_ground_slot", slot, true);
    if (context.updateGroundTextures) context.updateGroundTextures();
}
}
