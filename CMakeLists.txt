cmake_minimum_required(VERSION 3.16)
project(evaluate-mathematical-expression LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_definitions(-Wall -Wextra -Werror -Wconversion -pedantic -O2 -flto -Wl,--strip-all)
else ()
    add_definitions(-Wall -Wextra -Werror -Wconversion -pedantic)
endif ()

set(SYMBOL_LIB symbol)
set(CALCEME_LIB calc-eme)

file(GLOB SYMBOL_CPP_FILES "./lib/eme/symbol/*.cpp")
file(GLOB SYMBOL_H_FILES "./lib/eme/symbol/*.h")
add_library(${SYMBOL_LIB} STATIC ${SYMBOL_CPP_FILES} ${SYMBOL_H_FILES})

file(GLOB CALCEME_CPP_FILES "./lib/eme/*.cpp")
file(GLOB CALCEME_H_FILES "./lib/eme/*.h")
add_library(${CALCEME_LIB} STATIC ${CALCEME_CPP_FILES} ${CALCEME_H_FILES})

add_executable(${PROJECT_NAME} main.cpp lib/calc.hpp)
target_include_directories(${PROJECT_NAME} PRIVATE ./lib)

add_subdirectory(./thirdparty/googletest)
enable_testing()

add_subdirectory(./tests)

target_link_libraries(${PROJECT_NAME} ${CALCEME_LIB} ${SYMBOL_LIB})
