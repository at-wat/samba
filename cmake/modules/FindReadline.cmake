# Find readline library

find_path(READLINE_INCLUDE_DIRS readline/readline.h
	HINTS ENV READLINE_DIR
	PATH_SUFFIXES include
)
find_library(READLINE_LIBRARIES
	NAMES readline
	HINTS ENV READLINE_DIR
)
find_library(TINFO_LIBRARIES
  NAMES tinfo termcap ncursesw ncurses cursesw curses
)
if(TINFO_LIBRARIES)
	set(READLINE_LIBRARIES ${READLINE_LIBRARIES} ${TINFO_LIBRARIES})
endif(TINFO_LIBRARIES)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Readline
	DEFAULT_MSG READLINE_LIBRARIES
	READLINE_INCLUDE_DIRS
)
