cmake_minimum_required(VERSION 3.10)
project(Dungeon)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
  SDL3
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG main
)

FetchContent_MakeAvailable(SDL3)

FetchContent_Declare(
  SDL3_image
  GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
  GIT_TAG main
)

set(SDLIMAGE_SDL3 ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(SDL3_image)

FetchContent_Declare(
  SDL3_mixer
  GIT_REPOSITORY https://github.com/libsdl-org/SDL_mixer.git
  GIT_TAG main
)

set(SDLMIXER_SDL3 ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(SDL3_mixer)

add_executable(dungeon
    src/dungeon.cc
    src/game.cc
    src/maze/maze.cc
)

target_link_libraries(dungeon PRIVATE
    SDL3::SDL3
    SDL3_image::SDL3_image
    SDL3_mixer::SDL3_mixer
)
