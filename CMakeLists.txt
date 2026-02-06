cmake_minimum_required(VERSION 3.10)

project(space-invaders)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(space-invaders main.cpp enemy.cpp entity.cpp player.cpp projectile.cpp)

find_package(SFML 3.0 COMPONENTS Graphics Audio REQUIRED)

install(TARGETS space-invaders RUNTIME DESTINATION bin)

target_link_libraries(space-invaders PRIVATE SFML::Graphics SFML::Audio)

add_custom_command(TARGET space-invaders POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/bin/assets
)
