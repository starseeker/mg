set(MG_SRCS
  basic.c
  bell.c
  buffer.c
  chrdef.h
  cinfo.c
  def.h
  dir.c
  display.c
  echo.c
  extend.c
  file.c
  fileio.c
  funmap.c
  funmap.h
  help.c
  interpreter.c
  kbd.c
  kbd.h
  key.h
  keymap.c
  line.c
  macro.c
  macro.h
  main.c
  match.c
  modes.c
  paragraph.c
  pathnames.h
  region.c
  search.c
  spawn.c
  tty.c
  ttydef.h
  ttyio.c
  ttykbd.c
  undo.c
  util.c
  version.c
  window.c
  word.c
  yank.c
  )

if (ENABLE_AUTOEXEC)
  list(APPEND MG_SRCS autoexec.c)
endif()
if (ENABLE_CMODE)
  list(APPEND MG_SRCS cmode.c)
endif()
if (ENABLE_COMPILE)
  list(APPEND MG_SRCS grep.c)
endif()
if (ENABLE_CSCOPE)
  list(APPEND MG_SRCS cscope.c)
endif()
if (ENABLE_CTAGS)
  list(APPEND MG_SRCS tags.c)
endif()
if (ENABLE_DIRED)
  list(APPEND MG_SRCS dired.c)
endif()
if (ENABLE_REGEXP)
  list(APPEND MG_SRCS re_search.c)
endif()


set(lib_srcs
  fparseln
  futimens
  login_tty
  openpty
  reallocarray
  strlcat
  strlcpy
  strtonum
  )

foreach(lsrc ${lib_srcs})
  string(TOUPPER ${lsrc} ULSRC)
  if (NOT HAVE_${ULSRC})
    list(APPEND MG_SRCS ../lib/${lsrc}.c)
  endif ()
endforeach()

# For building without ncurses
list(APPEND MG_SRCS ansi.c ansi.h)

add_executable(mg ${MG_SRCS})
target_compile_definitions(mg PUBLIC -DDATADIR=\"${DATADIR}\" -DDOCDIR=\"${DOCDIR}\")
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

