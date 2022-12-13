cmake_minimum_required(VERSION 3.21)
project(TP_NFA037)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
#set(LIBRARY_PATH ${LIBRARY_PATH} "C:\\Users\\aperi\\programmation\\libraries\\SDL2-devel-2.26.0-mingw\\SDL2-2.26.0\\x86_64-w64-mingw32\\lib")
#set(lib_sdl2_image "${LIBRARY_PATH}\\SDL2_image.lib")
set(CMAKE_EXE_LINKER_FLAGS "-static-libstdc++")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} )

#find_package(SDL2_IMAGE REQUIRED)
#include_directories(${SDL2_IMAGE_INCLUDE_DIR})

add_executable(TP_NFA037 main.cpp Position.cpp Position.h Hero.cpp Hero.h Perso.cpp Perso.h Phantom.cpp Phantom.h Image.cpp Image.h Mouvement.cpp Mouvement.h Labyrinthe.cpp Labyrinthe.h Bloc.cpp Bloc.h Logger.cpp Logger.h Labyrinth_Exception.h Key.cpp Key.h Arrows.cpp Arrows.h Wall.cpp Wall.h Door.cpp Door.h Food.cpp Food.h Game.cpp Game.h FoodListener.h Fruit.cpp Fruit.h)
target_link_libraries(TP_NFA037 ${SDL2_LIBRARY}
        #${SDL2_IMAGE_LIBRARIES}
        #${lib_sdl2_image}
        )
