cmake_minimum_required(VERSION 3.13)
project(termbox
        LANGUAGES C
        VERSION 2.0
        DESCRIPTION "Library for writing text-based user interfaces"
        HOMEPAGE_URL "https://github.com/mame98/termbox"
        )

set(CMAKE_C_STANDARD 11)

option(ENABLE_CLANG_TIDY "Check the code by using clang-tidy during compilation" OFF)
option(ENABLE_CLANG_FORMAT "Use clang format to auto-format source files" OFF)
option(ENABLE_CPPCHECK "Use CppCheck for static analysis" OFF)


if(ENABLE_CLANG_TIDY)
    set(CLANG_TIDY_CHECKS "bugprone-*,clang-analyzer-*,cert-*,performance-*,portability-*,readability-*" CACHE STRING "Checks to perform by clang-tidy")

    set(CMAKE_C_CLANG_TIDY
        clang-tidy;
        -header-filter=.;
        -checks=${CLANG_TIDY_CHECKS};)
endif()

if(ENABLE_CLANG_FORMAT)
    file(GLOB_RECURSE FILES_TO_FORMAT *.c *.h)

    find_program(CLANG_FORMAT NAMES clang-format)
    add_custom_target(
            autoformat
            COMMAND ${CLANG_FORMAT}
            -style=file
            -i
            ${FILES_TO_FORMAT}
    )
endif()

if(ENABLE_CPPCHECK)
    find_program(CMAKE_C_CPPCHECK NAMES cppcheck)
    if (CMAKE_C_CPPCHECK)
        list(
                APPEND CMAKE_C_CPPCHECK
                "--enable=warning"
        )
    endif()
endif()



add_subdirectory(src)

install(FILES README.md Changelog.md COPYING DESTINATION share/doc/termbox/)

# CPack for distribution
set(CPACK_GENERATOR "TGZ;STGZ")
set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/COPYING")
set(CPACK_RESOURCE_FILE_README "${PROJECT_SOURCE_DIR}/README.md")
set(CPACK_PACKAGING_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")
set(CPACK_PACKAGE_VENDOR "Termbox Authors")
set(CPACK_PACKAGE_CHECKSUM SHA1)
include(CPack)