# Find ncurses library (support static linking)

find_path(NCURSES_INCLUDE_DIRS ncurses/ncurses.h
	HINTS ENV NCURSES_DIR
	PATH_SUFFIXES include
)
find_library(NCURSES_LIBRARIES_FOUND
	NAMES ncurses tinfo
  HINTS ENV NCURSES_DIR
)
if(NCURSES_LIBRARIES_FOUND)
	set(NCURSES_LIBRARIES ncurses tinfo)
endif(NCURSES_LIBRARIES_FOUND)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(NCURSES
	DEFAULT_MSG NCURSES_LIBRARIES
	NCURSES_INCLUDE_DIRS
)

