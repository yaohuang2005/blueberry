set(GOOGLETEST_VERSION 1.9.0)

add_subdirectory(lib/googletest/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(../src/include)

file(GLOB BLUEBERRY_TEST_SOURCES "${PROJECT_SOURCE_DIR}/test/*/*test.cpp")


add_custom_target(build-tests COMMAND ${CMAKE_CTEST_COMMAND} --show-only)
add_custom_target(check-tests COMMAND ${CMAKE_CTEST_COMMAND} --verbose)


foreach (blueberry_test_source ${BLUEBERRY_TEST_SOURCES})
    # Create a human readable name.
    get_filename_component(blueberry_test_filename ${blueberry_test_source} NAME)
    string(REPLACE ".cpp" "" blueberry_test_name ${blueberry_test_filename})

    # Add the test target separately and as part of "make check-tests".
    add_executable(${blueberry_test_name} EXCLUDE_FROM_ALL ${blueberry_test_source})
    add_dependencies(build-tests ${blueberry_test_name})
    add_dependencies(check-tests ${blueberry_test_name})

    target_link_libraries(${blueberry_test_name} blueberry_shared gtest gmock_main)

    # Set test target properties and dependencies.
    set_target_properties(${blueberry_test_name}
            PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test"
            COMMAND ${blueberry_test_name}
            )

    # Add the test under CTest.
    add_test(${blueberry_test_name} ${VALGRIND_BIN} ${VALGRIND_OPTIONS}
            --suppressions=${VALGRIND_SUPPRESSIONS_FILE} ${CMAKE_BINARY_DIR}/test/${blueberry_test_name}
            --gtest_color=yes --gtest_output=xml:${CMAKE_BINARY_DIR}/test/unit_${test_name}.xml)
    add_test(${blueberry_test_name} ${CMAKE_BINARY_DIR}/test/${blueberry_test_name} --gtest_color=yes
            --gtest_output=xml:${CMAKE_BINARY_DIR}/test/${blueberry_test_name}.xml)
endforeach(blueberry_test_source ${BLUEBERRY_TEST_SOURCES})
