set(MG_SRCS
  basic.c
  bell.c
  buffer.c
  cinfo.c
  dir.c
  display.c
  echo.c
  extend.c
  file.c
  fileio.c
  funmap.c
  help.c
  interpreter.c
  kbd.c
  keymap.c
  line.c
  macro.c
  main.c
  match.c
  modes.c
  paragraph.c
  region.c
  search.c
  spawn.c
  tty.c
  ttyio.c
  ttykbd.c
  ttydef.h
  undo.c
  util.c
  version.c
  window.c
  word.c
  yank.c
  chrdef.h
  def.h
  funmap.h
  kbd.h
  key.h
  macro.h
  pathnames.h
  )

list(APPEND MG_SRCS ../lib/strtonum.c)

# For building without ncurses
list(APPEND MG_SRCS ansi.c ansi.h)

add_executable(mg ${MG_SRCS})
install(TARGETS mg
  RUNTIME DESTINATION ${BIN_DIR}
  LIBRARY DESTINATION ${LIB_DIR}
  ARCHIVE DESTINATION ${LIB_DIR}
  )

# Local Variables:
# tab-width: 8
# mode: cmake
# indent-tabs-mode: t
# End:
# ex: shiftwidth=2 tabstop=8

