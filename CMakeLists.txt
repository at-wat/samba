cmake_minimum_required(VERSION 3.0.2)
project(samba)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)

find_package(Curses REQUIRED)
find_package(Readline REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

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
  ${CURSES_LIBRARIES}
)

install(TARGETS samba)
