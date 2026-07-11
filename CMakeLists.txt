cmake_minimum_required(VERSION 3.21)
project("project-name")

include("bread/cmake/engine.cmake")
add_subdirectory("bread")

file(GLOB GAME_SRC
    game/main.cpp
    game/my_game.cpp
)

bread_project(
    NAME
        "project-name"

    PACKAGES
        

    SOURCES
        ${GAME_SRC}
)

