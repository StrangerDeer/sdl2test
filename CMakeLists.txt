cmake_minimum_required(VERSION 3.26)
project(sdl2test)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

set(SDL2_PATH "SDL2\\SDL2-2.28.2\\x86_64-w64-mingw32")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

set(SDL2_IMAGE_PATH "SDL2\\SDL2_image-2.8.0\\x86_64-w64-mingw32")
find_package(SDL2_image REQUIRED)
include_directories( ${SDL2_IMAGE_INCLUDE_DIRS})
link_directories(${SDL2_IMAGE_LIB_DIR})


set(PROJECT_HEADERS
        ui/TextureCreator.h
        ui/BoardUI.h
        logic/BoardLogic.h
        Game.h
)

set(PROJECT_SOURCES
        main.cpp
        ui/TextureCreator.cpp
        ui/BoardUI.cpp
        logic/BoardLogic.cpp
        Game.cpp
)

add_executable(sdl2test ${PROJECT_SOURCES} ${PROJECT_HEADERS})

target_link_libraries(sdl2test PRIVATE ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})