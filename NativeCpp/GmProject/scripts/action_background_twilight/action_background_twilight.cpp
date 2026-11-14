#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_twilight(BackgroundActionContext& context, const QVariant& value)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_twilight", "BG_TWILIGHT", value, 0.0))
        return;
    assignBackgroundValue(context, "action_background_twilight", "background_twilight", value, false);
}
}
