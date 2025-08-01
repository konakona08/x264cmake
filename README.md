# VideoLAN X264 project with CMake makefile

## Initial purpose

Debug X264 under Visual Studio 2022 (default compiled X264 can't be source-debugged)

## Steps for usage

1. Configure project: ./configure --enable-static

2. Create project files using CMake (be sure to specify output/build dir, be default it's build and is ignored in gitignore!)

3. Compile project as you please