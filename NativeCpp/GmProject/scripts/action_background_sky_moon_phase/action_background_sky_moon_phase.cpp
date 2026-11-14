#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_sky_moon_phase(BackgroundActionContext& context, const QVariant& phase)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEditWithHistory(context, "action_background_sky_moon_phase",
                                     "BG_SKY_MOON_PHASE", phase, 0.0, false))
        return;
    assignBackgroundValue(context, "action_background_sky_moon_phase",
                          "background_sky_moon_phase", phase, true);
}
}
