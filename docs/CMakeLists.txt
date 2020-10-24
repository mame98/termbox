configure_file(Doxyfile.in Doxyfile)

find_package(Doxygen)

if(DOXYGEN_FOUND)

    add_custom_target(generateAPIDocs
            COMMAND ${DOXYGEN_EXECUTABLE}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Running Doxygen to generate API documentation"
            BYPRODUCTS  ${CMAKE_CURRENT_BINARY_DIR}/html
                        ${CMAKE_CURRENT_BINARY_DIR}/xml
                        ${CMAKE_CURRENT_BINARY_DIR}/latex
            VERBATIM
    )
else()
    message(STATUS "Doxygen was not found - skipping documentation generation")
endif()