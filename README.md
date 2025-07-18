# stm32-monorepo-test
Pre commit with clang format
pip install pre-commit - auto does clang format when we have the pre commit config yaml and the clang format files in repo

github workflow - check clang format, make sure code builds
workflow happens automatically once configured

.gitignore

mono repo
each sub folder will have its own cmake lists to compile itself
there will be one superbuild cmalists in the root, this one will be set to build all the other cmaklists and will be run on workflow
also if this one is set to cmake directory in vscode intellisense should work in all the folders at the same time