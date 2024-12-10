# Minimum required version of CMake
cmake_minimum_required(VERSION 3.18)

# Set CMake project name
project(MG)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_CURRENT_BINARY_DIR}
  )

file(WRITE ${CMAKE_BINARY_DIR}/config.h "#define WITHOUT_CURSES 1\n")
file(APPEND ${CMAKE_BINARY_DIR}/config.h "#define PACKAGE_NAME \"mg\"\n")
file(APPEND ${CMAKE_BINARY_DIR}/config.h "#define PACKAGE_STRING \"mg -1\"\n")

if (NOT DEFINED BIN_DIR)
  set (BIN_DIR bin)
endif (NOT DEFINED BIN_DIR)

if (NOT DEFINED LIB_DIR)
  set (LIB_DIR lib)
endif (NOT DEFINED LIB_DIR)

add_subdirectory(src)

# Local Variables:
# tab-width: 8
# mode: cmake
# indent-tabs-mode: t
# End:
# ex: shiftwidth=2 tabstop=8

