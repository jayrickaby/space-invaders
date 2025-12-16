cmake_minimum_required(VERSION 3.10)

project(invaders-for-henry)

add_executable(invaders-for-henry main.cpp)

install(TARGETS invaders-for-henry RUNTIME DESTINATION bin)
