# Minimum required version of CMake
cmake_minimum_required(VERSION 3.18)

# Set CMake project name
project(MG)

option(ENABLE_AUTOEXEC "auto-execute support" ON )
option(ENABLE_CMODE "C-mode support" ON)
option(ENABLE_COMPILE "C compile & grep mode, used by C-mode" ON )
option(ENABLE_CSCOPE "Cscope support" ON )
option(ENABLE_CTAGS "ctags(1) support, required by Cscope" ON)
option(ENABLE_DIRED "directory editor" ON)
option(ENABLE_REGEXP "full regexp search" ON)
option(ENABLE_CURSES "use system (n)curses package" ON)

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

# Translate options to defines
if(ENABLE_COMPILE)
  set(ENABLE_COMPILE_GREP ON)
endif()

# mg can build without curses, but will use it if
# it is present.
if(ENABLE_CURSES)
  find_package(Curses)
endif()

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

