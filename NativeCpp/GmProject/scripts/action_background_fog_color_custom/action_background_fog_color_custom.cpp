#include "../../../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_fog_color_custom(BackgroundActionContext& context, const QVariant& custom)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_fog_color_custom",
                          "BG_FOG_CUSTOM_COLOR", custom, false))
        return;
    assignBackgroundValue(context, "action_background_fog_color_custom",
                          "background_fog_color_custom", custom, false);
}
}
