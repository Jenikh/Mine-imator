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
| Native C++ files created in this rewrite | 65 |
| Remaining GML files | 2,002 |

### By subsystem

| Subsystem | GML files | Ported |
|---|---:|---:|
| `scripts/action_background_*` | 64 | 64 |
| `scripts/access_error` | 1 | 1 |
| Everything else | 2,002 | 0 |

## Translated files

`NativeCpp/Common/BackgroundActionContext.hpp` is the shared adapter boundary for
every background action. It owns value/timeline semantics, resource selection
and reference counting, biome resolution and history recording; nothing in this
directory depends on the GameMaker runtime.

- `GmProject/scripts/access_error/access_error.gml` → `NativeCpp/GmProject/scripts/access_error/access_error.cpp`

The following background actions are ported, each `action_background_<name>.gml`
to the matching `.cpp`:

- atmosphere: `ambient_color`, `fog_color`, `fog_color_custom`,
  `fog_custom_object_color`, `fog_distance`, `fog_height`, `fog_object_color`,
  `fog_show`, `fog_size`, `fog_sky`, `foliage_color`, `grass_color`, `night_color`,
  `sunlight_angle`, `sunlight_color`, `sunlight_strength`, `texture_animation_speed`,
  `twilight`, `water_color`
- ground: `ground_show`, `ground_slot`, `ground_tex`, `ground_tex_material`,
  `ground_tex_normal`, `biome`
- image: `image`, `image_box_mapped`, `image_rotation`, `image_show`,
  `image_save_map`, `image_stretch`, `image_type`
- sky: `sky_color`, `sky_rotation`, `sky_time`, `sky_clouds_color`,
  `sky_clouds_height`, `sky_clouds_mode`, `sky_clouds_offset`, `sky_clouds_show`,
  `sky_clouds_size`, `sky_clouds_speed`, `sky_clouds_tex`, `sky_clouds_thickness`,
  `sky_moon_angle`, `sky_moon_phase`, `sky_moon_scale`, `sky_moon_tex`,
  `sky_sun_angle`, `sky_sun_scale`, `sky_sun_tex`
- leaves: `leaves_acacia_color`, `leaves_birch_color`, `leaves_dark_oak_color`,
  `leaves_jungle_color`, `leaves_mangrove_color`, `leaves_oak_color`,
  `leaves_spruce_color`
- wind: `wind`, `wind_direction`, `wind_directional_speed`,
  `wind_directional_strength`, `wind_speed`, `wind_strength`

### Adapter contract

`BackgroundActionContext` is supplied by the application. The background actions
rely on these callbacks:

- timeline/history: `selectBackground`, `timelineBegin`, `timelineSet`,
  `timelineDone`, `recordHistory`
- refresh: `refreshResourceColors`, `markLibraryPreviewDirty`,
  `updateGroundTextures`, `updateGroundTexturesMaterial`,
  `updateGroundTexturesNormal`, `updateClouds`
- resources (`action_background_*_tex`, `_image`, `ground_tex*`): `undoResource`,
  `redoResource`, `browseResourceFile`, `libraryFileExists`, `createResource`,
  `recordResourceHistory`, `releaseResource`, `retainResource`
- biomes (`action_background_biome`): `resolveBiomeName`
- map export (`action_background_image_save_map`): `saveImageDialog`,
  `saveMapCubeImage`

Resource actions take a `BackgroundResourceRequest` (`none`, `existing`,
`browse`) instead of GameMaker's loose instance/`e_option.BROWSE` argument.

## Important

This is a staged rewrite, not yet a complete replacement application. Do not remove or disable `GmProject`, `CppGen`, or the existing build until all required behavior has been ported and the native implementation builds and passes tests.
