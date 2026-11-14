#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_sunlight_strength(BackgroundActionContext& context, double value, double add)
{
    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_sunlight_strength",
                          "BG_SUNLIGHT_STRENGTH", value / 100.0, add))
        return;
    if (context.historyUndo || context.historyRedo)
        value *= 100.0;

    assignBackgroundScaledValue(context, "action_background_sunlight_strength",
                                "background_sunlight_strength", value, add, 100.0);

    // Temporary bugfix for floating point issue
    if (context.values.value("background_sunlight_strength").toDouble() == 0.0)
        context.values.insert("background_sunlight_strength", 0.0);
}
}
