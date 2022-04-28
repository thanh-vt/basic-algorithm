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
set(WINDOWS_LIB c-commons.dll.a m)

file(GLOB BASIC_ALGORITHMS_SRC ./src/*.h ./src/*.c ./src/*/*.c ./src/*/*/*.c ./include/*.h ./lib/c-commons/*.h)
add_executable(basic-algorithms ${BASIC_ALGORITHMS_SRC})
target_link_libraries(basic-algorithms ${WINDOWS_LIB})
# cmake < 3.5 does not support copy multiple files using wildcards
set(MENU_FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/menu/arithmetic.menu.txt"
        "${CMAKE_CURRENT_SOURCE_DIR}/menu/basic-algorithms.menu.txt"
        "${CMAKE_CURRENT_SOURCE_DIR}/menu/counting.menu.txt"
        "${CMAKE_CURRENT_SOURCE_DIR}/menu/geometry.menu.txt"
        "${CMAKE_CURRENT_SOURCE_DIR}/menu/graph.menu.txt"
        "${CMAKE_CURRENT_SOURCE_DIR}/menu/matrix.menu.txt"
        "${CMAKE_CURRENT_SOURCE_DIR}/menu/numbers-sequence.menu.txt"
        "${CMAKE_CURRENT_SOURCE_DIR}/menu/searching.menu.txt"
        "${CMAKE_CURRENT_SOURCE_DIR}/menu/sorting.menu.txt"
        "${CMAKE_CURRENT_SOURCE_DIR}/menu/string-handling.menu.txt"
        )
foreach (file_i ${MENU_FILES})
    add_custom_command (
            TARGET basic-algorithms POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy "${file_i}" "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Copying menu banners to build directory"
    )
endforeach (file_i)


file(GLOB_RECURSE BASIC_ALGORITHMS_TEST ./test/*.cpp ./test/*/*.cpp ./src/*.h ./src/*/*.c ./src/*/*/*.c ./include/*.h ./lib/c-commons/*.h)
add_executable(basic-algorithms-test ${BASIC_ALGORITHMS_TEST})
target_link_libraries(basic-algorithms-test ${WINDOWS_LIB})

#Link with GoogleTest
target_link_libraries(basic-algorithms-test gtest gtest_main)

#Link with GoogleMock
target_link_libraries(basic-algorithms-test gmock gmock_main)

#file(GLOB MATRIX_TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/test/*/*.txt)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test/resources/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


