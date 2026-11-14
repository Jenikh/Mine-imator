#include "../../../Common/BackgroundActionContext.hpp"

namespace MineImator::Native
{
void action_background_image_save_map(BackgroundActionContext& context)
{
    const QString filename = context.saveImageDialog ? context.saveImageDialog("cube") : QString();

    if (!filename.isEmpty() && context.saveMapCubeImage)
        context.saveMapCubeImage(filename);
}
}
