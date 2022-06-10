cmake_minimum_required(VERSION 3.23.1)


project(GameOfLife)


add_executable(${PROJECT_NAME} "")


target_sources(${PROJECT_NAME} PRIVATE main.c game/life.c game/life.h)