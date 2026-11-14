#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_fog_sky(BackgroundActionContext& context, const QVariant& show)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_fog_sky", "BG_FOG_SKY", show, 0.0))
        return;
    assignBackgroundValue(context, "action_background_fog_sky",
                          "background_fog_sky", show, false);
}
}
