#include "../../../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_fog_object_color(BackgroundActionContext& context, const QVariant& color)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_fog_object_color",
                          "BG_FOG_OBJECT_COLOR", color, false))
        return;
    assignBackgroundValue(context, "action_background_fog_object_color",
                          "background_fog_object_color", color, true);
}
}
