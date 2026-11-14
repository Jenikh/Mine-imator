#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_biome(BackgroundActionContext& context, const QVariant& biome)
{
    const QVariant resolvedBiome =
        context.resolveBiomeName ? QVariant(context.resolveBiomeName(biome)) : biome;

    if (!context.historyUndo && !context.historyRedo &&
        beginTimelineEdit(context, "action_background_biome", "BG_BIOME", resolvedBiome, 0.0))
        return;

    assignBackgroundValue(context, "action_background_biome", "background_biome", resolvedBiome, true);

    if (context.refreshResourceColors) context.refreshResourceColors();
    if (context.markLibraryPreviewDirty) context.markLibraryPreviewDirty();
}
}
