cmake_minimum_required(VERSION 3.10)
project(Dungeon)

include(FetchContent)

FetchContent_Declare(
  SDL3
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG main
)

FetchContent_MakeAvailable(SDL3)

add_executable(dungeon)

target_sources(dungeon
    PRIVATE
        src/dungeon.cc
        src/maze/maze.cc
)

#target_compile_options(dungeon PRIVATE -g -fsanitize=address)
#target_link_options(dungeon PRIVATE -fsanitize=address)

target_link_libraries(dungeon PRIVATE SDL3::SDL3)
