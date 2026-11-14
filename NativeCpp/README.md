# Native C++ rewrite

This directory contains the independent C++ rewrite of Mine-imator's GameMaker implementation.

## Porting rules

- Each source `.gml` file is read before its C++ counterpart is written.
- Preserve the source-relative directory structure under `NativeCpp/GmProject/`.
- A source file named `name.gml` maps to `name.cpp`.
- Translate behavior into native C++ and the project's native libraries; do not embed GML as strings, copy it into comments as a substitute, or call CppGen.
- Preserve the original behavior, including event ordering, state changes, errors, and edge cases.
- Shared GameMaker runtime concepts must become explicit native C++ APIs rather than hidden dependencies on the old runtime.
- Keep a port ledger so incomplete, blocked, and verified files are distinguishable.

## Progress

| Metric | Count |
|---|---:|
| GML files in source repository | 2,067 |
| Native C++ files created in this rewrite | 17 |
| Remaining GML files | 2,050 |

## Translated files

1. `GmProject/scripts/access_error/access_error.gml` → `NativeCpp/GmProject/scripts/access_error/access_error.cpp`
2. `GmProject/scripts/action_background_ambient_color/action_background_ambient_color.gml` → matching `.cpp`
3. `GmProject/scripts/action_background_fog_color/action_background_fog_color.gml` → matching `.cpp`
4. `GmProject/scripts/action_background_fog_color_custom/action_background_fog_color_custom.gml` → matching `.cpp`
5. `GmProject/scripts/action_background_fog_distance/action_background_fog_distance.gml` → matching `.cpp`
6. `GmProject/scripts/action_background_fog_height/action_background_fog_height.gml` → matching `.cpp`
7. `GmProject/scripts/action_background_fog_show/action_background_fog_show.gml` → matching `.cpp`
8. `GmProject/scripts/action_background_fog_size/action_background_fog_size.gml` → matching `.cpp`
9. `GmProject/scripts/action_background_fog_sky/action_background_fog_sky.gml` → matching `.cpp`
10. `GmProject/scripts/action_background_fog_object_color/action_background_fog_object_color.gml` → matching `.cpp`
11. `GmProject/scripts/action_background_fog_custom_object_color/action_background_fog_custom_object_color.gml` → matching `.cpp`
12. `GmProject/scripts/action_background_foliage_color/action_background_foliage_color.gml` → matching `.cpp`
13. `GmProject/scripts/action_background_grass_color/action_background_grass_color.gml` → matching `.cpp`
14. `GmProject/scripts/action_background_ground_show/action_background_ground_show.gml` → matching `.cpp`
15. `GmProject/scripts/action_background_ground_slot/action_background_ground_slot.gml` → matching `.cpp`
16. `GmProject/scripts/action_background_image_box_mapped/action_background_image_box_mapped.gml` → matching `.cpp`
17. `GmProject/scripts/action_background_image_rotation/action_background_image_rotation.gml` → matching `.cpp`

The sixteen background actions use `NativeCpp/Common/BackgroundActionContext.hpp` for timeline edits, undo/redo suppression, history recording, and background state. The application must provide the adapter callbacks and register these translation units in its build.

## Important

This is a staged rewrite, not yet a complete replacement application. Do not remove or disable `GmProject`, `CppGen`, or the existing build until all required behavior has been ported and the native implementation builds and passes tests.
