cmake_minimum_required(VERSION 3.16)
project(basic-algorithms)
#project(basic-algorithms C)
#set(CMAKE_C_STANDARD 11)

#Add the google test subdirectory
add_subdirectory(lib/googletest)

#include googletest/include dir
include_directories(lib/googletest/googletest/include)

#include the googlemock/include dir
include_directories(lib/googletest/googlemock/include)

include_directories(lib/c-commons)
include_directories(include)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

link_directories(lib/c-commons)

# m is lib definition of <math.h>
set(LINUX_LIB "${CMAKE_CURRENT_BINARY_DIR}/libc-commons.so" m)

file(GLOB BASIC_ALGORITHMS_SRC ./src/*.h ./src/*.c ./src/*/*.c ./src/*/*/*.c ./include/*.h ./lib/c-commons/*.h)
add_executable(basic-algorithms ${BASIC_ALGORITHMS_SRC})
target_link_libraries(basic-algorithms ${LINUX_LIB} m)
add_custom_command(
        TARGET basic-algorithms POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/menu/*.menu.txt" "${CMAKE_CURRENT_BINARY_DIR}"
        COMMENT "Copying menu banners to build directory"
)

file(GLOB_RECURSE BASIC_ALGORITHMS_TEST ./test/*.cpp ./test/*/*.cpp ./src/*.h ./src/*/*.c ./src/*/*/*.c ./include/*.h ./lib/c-commons/*.h)
add_executable(basic-algorithms-test ${BASIC_ALGORITHMS_TEST})
target_link_libraries(basic-algorithms-test ${LINUX_LIB} m)

#Link with GoogleTest
target_link_libraries(basic-algorithms-test gtest gtest_main)

#Link with GoogleMock
target_link_libraries(basic-algorithms-test gmock gmock_main)

file(GLOB MATRIX_TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/test/arithmetic-test/*.txt)

