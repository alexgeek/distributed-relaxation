find_package(Check REQUIRED)
include_directories(${CHECK_INCLUDE_DIRS})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

set(LIBCHECK_DEPS m rt pthread)

add_executable(check_matrix check_matrix.c)
target_link_libraries(check_matrix thelib ${CHECK_LIBRARIES} ${LIBCHECK_DEPS})

add_executable(check_image check_image.c)
target_link_libraries(check_image thelib ${CHECK_LIBRARIES} ${LIBCHECK_DEPS})

add_executable(check_thread check_thread.c)
target_link_libraries(check_thread thelib ${CHECK_LIBRARIES} ${LIBCHECK_DEPS})
