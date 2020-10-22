add_library(termbox STATIC
        termbox.c
        utf8.c
        )

target_include_directories(termbox PUBLIC ${CMAKE_CURRENT_LIST_DIR}/..)