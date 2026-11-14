#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_wind(BackgroundActionContext& context, const QVariant& value)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_wind", "BG_WIND", value, 0.0))
        return;
    assignBackgroundValue(context, "action_background_wind", "background_wind", value, false);
}
}
