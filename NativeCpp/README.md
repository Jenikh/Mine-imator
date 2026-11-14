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
| Native C++ files created in this rewrite | 1 |
| Remaining GML files | 2,066 |

## First translated file

- Source: `GmProject/scripts/access_error/access_error.gml`
- Native: `NativeCpp/GmProject/scripts/access_error/access_error.cpp`
- Translation: `show_message(...) ` becomes a native Qt `QMessageBox::critical(...)` call.

## Important

This is a staged rewrite, not yet a complete replacement application. Do not remove or disable `GmProject`, `CppGen`, or the existing build until all required behavior has been ported and the native implementation builds and passes tests.
