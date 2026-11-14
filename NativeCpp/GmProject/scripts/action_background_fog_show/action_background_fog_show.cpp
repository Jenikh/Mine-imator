#include "../../../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_fog_show(BackgroundActionContext& context, const QVariant& show)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_fog_show", "BG_FOG_SHOW", show, false))
        return;
    assignBackgroundValue(context, "action_background_fog_show",
                          "background_fog_show", show, false);
}
}
