cmake_minimum_required(VERSION 3.23.1)


project(GameOfLife)


add_executable(${PROJECT_NAME} "")


target_sources(${PROJECT_NAME} PRIVATE main.c game/life.c game/life.h gui/life_gui.c)

add_subdirectory(gui)

find_package(SDL2 REQUIRED)
include_directories(
    PUBLIC ${SDL2_INCLUDE_DIRS}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
