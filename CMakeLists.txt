cmake_minimum_required(VERSION 3.17)
project(evaluate-mathematical-expression LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror -Wconversion -pedantic")
#set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Wconversion -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

include_directories(lib)

add_subdirectory(thirdparty/googletest)
enable_testing()
include_directories(thirdparty/googletest/googletest/include)
include_directories(thirdparty/googletest/googlemock/include)

add_subdirectory(tests)

add_executable(evaluate-mathematical-expression main.cpp)
target_link_libraries(evaluate-mathematical-expression gtest gtest_main gmock gmock_main)
