#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_fog_custom_object_color(BackgroundActionContext& context, const QVariant& custom)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_fog_custom_object_color",
                          "BG_FOG_CUSTOM_OBJECT_COLOR", custom, 0.0))
        return;
    assignBackgroundValue(context, "action_background_fog_custom_object_color",
                          "background_fog_custom_object_color", custom, false);
}
}
