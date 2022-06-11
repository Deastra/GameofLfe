cmake_minimum_required(VERSION 3.0.1)

project(GameOfLife)

set(CMAKE_C_STANDART 11)

add_executable(${PROJECT_NAME} main.c)

add_subdirectory(gui)
add_subdirectory(game)

target_include_directories(${PROJECT_NAME}
    # PUBLIC ${SDL2_INCLUDE_DIRS}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC gui
)

target_link_libraries(${PROJECT_NAME} gui)

