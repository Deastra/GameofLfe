#creating new library
add_library(gui life_gui.c)

# finding required package
find_package(
  SDL2 REQUIRED
)

# linking included libraries
target_link_libraries(gui
  ${SDL2_LIBRARIES}
  game
)

# importing include directory
target_include_directories(gui
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} 
  PUBLIC ${SDL2_INCLUDE_DIRS} 
)

