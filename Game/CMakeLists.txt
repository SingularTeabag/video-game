cmake_minimum_required(VERSION 4.0)
project(Game C)

set(CMAKE_C_STANDARD 17)

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)

add_executable(Game src/main.c)

target_link_libraries(Game PRIVATE glfw glad::glad)