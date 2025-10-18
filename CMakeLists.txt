cmake_minimum_required(VERSION 3.21)
project("project-name")

include("bread/cmake/engine.cmake")
add_subdirectory("bread")

file(GLOB GAME_SRC
    game/main.cpp
    game/main_scene.cpp
)

bread_project("project-name" ${GAME_SRC})
