add_library(termbox STATIC
        termbox.c
        utf8.c
        )

target_include_directories(termbox PUBLIC ${CMAKE_CURRENT_LIST_DIR}/..)
target_compile_options(termbox PRIVATE -Wall -Wextra -Wpedantic)
target_compile_definitions(termbox PRIVATE -D_XOPEN_SOURCE)

install(TARGETS termbox)
install(FILES termbox.h DESTINATION include)