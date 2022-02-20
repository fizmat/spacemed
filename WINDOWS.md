
- extract SDL2-devel and SDL2_image-devel zips somewhere for example in ./libs
- create empty ./build, go there
- `'/c/Program Files/CMake/bin/cmake' -DSDL2_PATH="$PWD/../libs/SDL2-2.0.20" -DSDL2_IMAGE_PATH="$PWD/../libs/SDL2_image-2.0.5" ..`
    - in git bash with cmake not in PATH, adapt to your situation
- open solution in Visual Studio and build
- TODO: mingw?