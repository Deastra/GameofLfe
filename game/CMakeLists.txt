#creating new library
add_library(game life.c)

# importing include directory
target_include_directories(game
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} 
)

