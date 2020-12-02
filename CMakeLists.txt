cmake_minimum_required(VERSION 3.16)
project(evaluate-mathematical-expression LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror -Wconversion -pedantic")
#set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Wconversion -pedantic")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_definitions(-Wall -Wextra -Werror -Wconversion -pedantic -O2 -flto -Wl,--strip-all)
else()
    add_definitions(-Wall -Wextra -Werror -Wconversion -pedantic)
endif()

include_directories(lib)

add_subdirectory(thirdparty/googletest)
enable_testing()
include_directories(thirdparty/googletest/googletest/include)
include_directories(thirdparty/googletest/googlemock/include)

add_subdirectory(tests)

add_library(symbol STATIC
        lib/eme/symbol.h lib/eme/symbol.cpp
        lib/eme/symbol_sequence.h lib/eme/symbol_sequence.cpp)

add_library(calc-eme STATIC
        lib/eme/a_expression.h lib/eme/a_expression.cpp

        lib/eme/number.h lib/eme/number.cpp

        lib/eme/a_operator.h lib/eme/a_operator.cpp

        lib/eme/a_unary_operator.h lib/eme/a_unary_operator.cpp
        lib/eme/negative.h lib/eme/negative.cpp

        lib/eme/a_binary_operator.h lib/eme/a_binary_operator.cpp
        lib/eme/subtract.h lib/eme/subtract.cpp
        lib/eme/addition.h lib/eme/addition.cpp
        lib/eme/divide.h lib/eme/divide.cpp
        lib/eme/multiply.h lib/eme/multiply.cpp

        lib/eme/scope.h lib/eme/scope.cpp

        lib/eme/calculator.h lib/eme/calculator.cpp)

add_executable(evaluate-mathematical-expression main.cpp lib/calc.hpp)

target_link_libraries(evaluate-mathematical-expression
        calc-eme symbol
        gtest gtest_main gmock gmock_main)
