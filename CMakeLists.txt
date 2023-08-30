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

add_executable(TP_NFA037 src/main.cpp src/Characters/Position.cpp src/Characters/Position.h src/Characters/Hero.cpp src/Characters/Hero.h src/Characters/Perso.cpp src/Characters/Perso.h
        src/Characters/PhantomBlue.cpp src/Characters/PhantomBlue.h src/UI/Sprites.cpp src/UI/Sprites.h src/Core/Mouvement.cpp src/Core/Mouvement.h src/Core/Labyrinthe.cpp src/Core/Labyrinthe.h src/Environment/Bloc.cpp src/Environment/Bloc.h src/Logger.cpp src/Logger.h
        src/Labyrinth_Exception.h src/UI/Key.cpp src/UI/Key.h src/UI/Arrows.cpp src/UI/Arrows.h src/Environment/Wall.cpp src/Environment/Wall.h src/Environment/Door.cpp src/Environment/Door.h src/Environment/Food.cpp src/Environment/Food.h src/Core/Game.cpp src/Core/Game.h src/Callbacks/FoodListener.h src/Environment/Fruit.cpp
        src/Environment/Fruit.h src/Characters/Phantom.cpp src/Characters/Phantom.h src/Callbacks/Vulnerability_Callback.h src/Characters/PhantomRed.cpp src/Characters/PhantomRed.h src/Characters/PhantomPink.cpp src/Characters/PhantomPink.h src/Characters/PhantomOrange.cpp src/Characters/PhantomOrange.h src/UI/Window.cpp src/UI/Window.h src/Callbacks/Phantom_Callback.h)
target_link_libraries(TP_NFA037 ${SDL2_LIBRARY}
        #${SDL2_IMAGE_LIBRARIES}
        #${lib_sdl2_image}
        )
