# Minimum required version of CMake
cmake_minimum_required(VERSION 3.18)

# Set CMake project name
project(MG)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_CURRENT_BINARY_DIR}
  )

include(CheckIncludeFiles)
check_include_files(pty.h HAVE_PTY_H)
check_include_files(utmp.h HAVE_UTMP_H)

include(CheckFunctionExists)
check_function_exists(fparseln HAVE_FPARSELN)
check_function_exists(futimens HAVE_FUTIMENS)
check_function_exists(login_tty HAVE_LOGIN_TTY)
check_function_exists(openpty HAVE_OPENPTY)
check_function_exists(reallocarray HAVE_REALLOCARRAY)
check_function_exists(strlcat HAVE_STRLCAT)
check_function_exists(strlcpy HAVE_STRLCPY)
check_function_exists(strtonum HAVE_STRTONUM)

configure_file(config.h.cmake ${CMAKE_BINARY_DIR}/config.h)

if (NOT DEFINED BIN_DIR)
  set (BIN_DIR bin)
endif (NOT DEFINED BIN_DIR)

if (NOT DEFINED LIB_DIR)
  set (LIB_DIR lib)
endif (NOT DEFINED LIB_DIR)

set(DATADIR "share")
set(DOCDIR "share/doc")

add_subdirectory(src)

# Local Variables:
# tab-width: 8
# mode: cmake
# indent-tabs-mode: t
# End:
# ex: shiftwidth=2 tabstop=8

