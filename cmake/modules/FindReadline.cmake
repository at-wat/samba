# Find readline library

find_path(READLINE_INCLUDE_DIRS readline/readline.h
	HINTS ENV READLINE_DIR
	PATH_SUFFIXES include
)
find_library(READLINE_LIBRARIES
	NAMES readline
	HINTS ENV READLINE_DIR
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Readline
	DEFAULT_MSG READLINE_LIBRARIES
	READLINE_INCLUDE_DIRS
)
