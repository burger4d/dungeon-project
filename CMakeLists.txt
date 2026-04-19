cmake_minimum_required(VERSION 3.10)
project(Dungeon)

include(FetchContent)

FetchContent_Declare(
  SDL3
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG main
)

FetchContent_MakeAvailable(SDL3)

add_executable(dungeon src/dungeon.cc)

target_link_libraries(dungeon PRIVATE SDL3::SDL3)
