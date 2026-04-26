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
    src/utils/utils.cc
    src/weapon/weapon.cc
    src/maze/maze.cc
)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        main
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)


add_executable(test_weapon
  src/utils/utils.cc
  src/weapon/weapon.cc
  src/weapon/test-weapon.cc
)

target_include_directories(test_weapon PRIVATE include)

target_link_libraries(test_weapon PRIVATE
  gtest
  gtest_main
  pthread
)
gtest_discover_tests(test_weapon)

add_executable(test_dice
  src/utils/utils.cc
  src/utils/test-dice.cc
)

target_include_directories(test_dice PRIVATE include)

target_link_libraries(test_dice PRIVATE
  gtest
  gtest_main
  pthread
)
gtest_discover_tests(test_dice)

target_link_libraries(dungeon PRIVATE
    SDL3::SDL3
    SDL3_image::SDL3_image
    SDL3_mixer::SDL3_mixer
)