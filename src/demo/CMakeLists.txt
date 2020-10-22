add_executable(keyboard keyboard.c)
target_link_libraries(keyboard PRIVATE termbox)

add_executable(output output.c)
target_link_libraries(output PRIVATE termbox)

add_executable(paint paint.c)
target_link_libraries(paint PRIVATE termbox)
