file(GLOB_RECURSE test_cases *.cpp)
foreach (case_file ${test_cases})
    get_filename_component(case_name ${case_file} NAME_WE)
    set(case_name tests_${case_name})

    add_executable(${case_name} ${case_file})

    target_link_libraries(${case_name} ${LINK_LIBS}
            calc-eme symbol
            gtest gtest_main gmock gmock_main pthread)

    add_test(NAME ${case_name}
            COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${case_name}
            WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
endforeach ()
