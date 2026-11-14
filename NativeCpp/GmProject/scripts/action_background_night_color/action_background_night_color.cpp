#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_night_color(BackgroundActionContext& context, const QVariant& color)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_night_color", "BG_NIGHT_COLOR", color, 0.0))
        return;
    assignBackgroundValue(context, "action_background_night_color", "background_night_color", color, true);
}
}
