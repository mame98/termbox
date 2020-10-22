cmake_minimum_required(VERSION 3.13)
project(termbox
        LANGUAGES C
        VERSION 2.0
        DESCRIPTION "Library for writing text-based user interfaces"
        HOMEPAGE_URL "https://github.com/mame98/termbox"
        )

set(CMAKE_C_STANDARD 11)

add_subdirectory(src)