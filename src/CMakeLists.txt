set(LIB_SOURCES
  matrix.c
  bmpfile.c
  image.c
  thread.c
)

set(MAIN_SOURCES
  main.c
  matrix.c
  image.c
  thread.c
  bmpfile.c
)

set(HEADERS
  matrix.h
  image.h
  thread.h
  bmpfile.h
)

set(LIB_DEPS
  m # math lib for unix
  pthread
)

add_library(thelib STATIC ${LIB_SOURCES} ${HEADERS})

add_executable(main ${HEADERS} ${MAIN_SOURCES})
target_link_libraries(main thelib ${LIB_DEPS})
