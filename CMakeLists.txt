cmake_minimum_required (VERSION 2.6)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules/")
set(CMAKE_BUILD_TYPE Debug)

project(theproject)

add_subdirectory(src)
add_subdirectory(tests)

enable_testing()
add_test(NAME check_matrix COMMAND check_matrix)
add_test(NAME check_image COMMAND check_image)
add_test(NAME check_thread COMMAND check_thread)
