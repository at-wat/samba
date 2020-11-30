cmake_minimum_required(VERSION 3.0.2)
project(samba)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)

option(ALL_STATIC "Static link libraries and libgcc" OFF)
if(ALL_STATIC)
  set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
endif(ALL_STATIC)

set(CURSES_NEED_NCURSES True)
find_package(Curses REQUIRED)
find_package(Readline REQUIRED)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${READLINE_INCLUDE_DIRS}
)

add_executable(samba
  src/batch.c
  src/cmdline.c
  src/comm.c
  src/crc-1021.c
  src/fsio.c
  src/sam.c
  src/samba.c
  src/sambaflash.c
  src/sambareset.c
)
target_link_libraries(samba
  ${READLINE_LIBRARIES}
  ncurses
)

install(TARGETS samba)
