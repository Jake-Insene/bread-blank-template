cmake_minimum_required(VERSION 3.21)
project("project-name")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_FLAGS} /GR- /EHsc- /Zc:preprocessor")
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:>")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
    set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} -fno-rtti -fno-exceptions -Wall -Wextra"
    )
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/lib/debug")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/lib/debug")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/bin/debug")
else()
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/lib")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/lib")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/bin")
endif()

add_subdirectory("bread")

file(GLOB GAME_SRC
    game/main.cpp
    game/main_scene.cpp
)

if(ANDROID)
    set(CMAKE_ANDROID_STL_TYPE "c++_static")
    set(CMAKE_SHARED_LINKER_FLAGS
        "${CMAKE_SHARED_LINKER_FLAGS} -u ANativeActivity_onCreate"
    )

    add_library(
      "project-name"
      SHARED
      ${GAME_SRC}
    )

elseif(WIN32)
    add_executable(
      "project-name"
      WIN32
      ${GAME_SRC}
    )
    if(MSVC)
        set_target_properties("project-name" PROPERTIES LINK_FLAGS "/ENTRY:wWinMainCRTStartup")
    endif()
endif()


target_compile_definitions("project-name" PUBLIC ${BREAD_BUILD_DEFINITIONS})

target_include_directories(
    "project-name"
    PUBLIC
    "bread/"
    "bread/src"
    "."
)

target_link_libraries(
    "project-name"
    "bread"
)

add_custom_command(
    TARGET "project-name"
    PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/bread/assets ${CMAKE_SOURCE_DIR}/assets
)

