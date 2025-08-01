# VideoLAN X264 project with CMake makefile

## Initial purpose

Debug X264 under Visual Studio 2022 (default compiled X264 can't be source-debugged)

## Steps for usage

1. Configure project: ./configure --disable-avs --disable-swscale --disable-lavf --disable-ffms --disable-gpac --disable-asm --disable-opencl --disable-interlaced --enable-shared --disable-thread --enable-pic --disable-cli --bit-depth=8

2. Create project files using CMake (be sure to specify output/build dir, by default it's build and is ignored in gitignore!)

3. Compile project as you please