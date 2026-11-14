#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_ambient_color(BackgroundActionContext& context, const QVariant& color)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_ambient_color", "BG_AMBIENT_COLOR", color, 0.0))
        return;
    assignBackgroundValue(context, "action_background_ambient_color",
                          "background_ambient_color", color, true);
}
}
