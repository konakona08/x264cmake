# VideoLAN X264 project with CMake makefile

## Initial purpose

Debug X264 under Visual Studio 2022 (default compiled X264 can't be source-debugged)

## Steps for usage

1. Configure project: ./configure --enable-static --disable-asm

NOTE: --disable-asm must be specified as VS2022 can't compile assembly-specific entries properly

2. Create project files using CMake (be sure to specify output/build dir, by default it's build and is ignored in gitignore!)

3. Compile project as you please