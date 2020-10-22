cmake_minimum_required(VERSION 3.13)
project(termbox
        LANGUAGES C
        VERSION 2.0
        DESCRIPTION "Library for writing text-based user interfaces"
        HOMEPAGE_URL "https://github.com/mame98/termbox"
        )

set(CMAKE_C_STANDARD 11)

option(ENABLE_CLANG_TIDY "Check the code by using clang-tidy during compilation" OFF)

if(ENABLE_CLANG_TIDY)
    set(CLANG_TIDY_CHECKS "bugprone-*,clang-analyzer-*,cert-*,performance-*,portability-*,readability-*" CACHE STRING "Checks to perform by clang-tidy")

    set(CMAKE_C_CLANG_TIDY
        clang-tidy;
        -header-filter=.;
        -checks=${CLANG_TIDY_CHECKS};)
endif()

add_subdirectory(src)