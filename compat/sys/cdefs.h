/*	$OpenBSD: cdefs.h,v 1.44 2024/07/30 05:57:31 guenther Exp $	*/
/*	$NetBSD: cdefs.h,v 1.16 1996/04/03 20:46:39 christos Exp $	*/

/*
 * Copyright (c) 1991, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Berkeley Software Design, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)cdefs.h	8.7 (Berkeley) 1/21/94
 */

#ifndef	_SYS_CDEFS_H_
#define	_SYS_CDEFS_H_

/*
 * "The nice thing about standards is that there are so many to choose from."
 * There are a number of "feature test macros" specified by (different)
 * standards that determine which interfaces and types the header files
 * should expose.
 *
 * Because of inconsistencies in these macros, we define our own
 * set in the private name space that end in _VISIBLE.  These are
 * always defined and so headers can test their values easily.
 * Things can get tricky when multiple feature macros are defined.
 * We try to take the union of all the features requested.
 *
 * The following macros are guaranteed to have a value after cdefs.h
 * has been included:
 *	__POSIX_VISIBLE
 *	__XPG_VISIBLE
 *	__ISO_C_VISIBLE
 *	__BSD_VISIBLE
 */

/*
 * X/Open Portability Guides and Single Unix Specifications.
 * _XOPEN_SOURCE				XPG3
 * _XOPEN_SOURCE && _XOPEN_VERSION = 4		XPG4
 * _XOPEN_SOURCE && _XOPEN_SOURCE_EXTENDED = 1	XPG4v2
 * _XOPEN_SOURCE == 500				XPG5
 * _XOPEN_SOURCE == 520				XPG5v2
 * _XOPEN_SOURCE == 600				POSIX 1003.1-2001 with XSI
 * _XOPEN_SOURCE == 700				POSIX 1003.1-2008 with XSI
 * _XOPEN_SOURCE == 800				POSIX 1003.1-2024 with XSI
 *
 * The XPG spec implies a specific value for _POSIX_C_SOURCE.
 */
#ifdef _XOPEN_SOURCE
# if (_XOPEN_SOURCE - 0 >= 800)
#  define __XPG_VISIBLE		800
#  undef _POSIX_C_SOURCE
#  define _POSIX_C_SOURCE	202405L
# elif (_XOPEN_SOURCE - 0 >= 700)
#  define __XPG_VISIBLE		700
#  undef _POSIX_C_SOURCE
#  define _POSIX_C_SOURCE	200809L
# elif (_XOPEN_SOURCE - 0 >= 600)
#  define __XPG_VISIBLE		600
#  undef _POSIX_C_SOURCE
#  define _POSIX_C_SOURCE	200112L
# elif (_XOPEN_SOURCE - 0 >= 520)
#  define __XPG_VISIBLE		520
#  undef _POSIX_C_SOURCE
#  define _POSIX_C_SOURCE	199506L
# elif (_XOPEN_SOURCE - 0 >= 500)
#  define __XPG_VISIBLE		500
#  undef _POSIX_C_SOURCE
#  define _POSIX_C_SOURCE	199506L
# elif (_XOPEN_SOURCE_EXTENDED - 0 == 1)
#  define __XPG_VISIBLE		420
# elif (_XOPEN_VERSION - 0 >= 4)
#  define __XPG_VISIBLE		400
# else
#  define __XPG_VISIBLE		300
# endif
#endif

/*
 * POSIX macros, these checks must follow the XOPEN ones above.
 *
 * _POSIX_SOURCE == 1		1003.1-1988 (superseded by _POSIX_C_SOURCE)
 * _POSIX_C_SOURCE == 1		1003.1-1990
 * _POSIX_C_SOURCE == 2		1003.2-1992
 * _POSIX_C_SOURCE == 199309L	1003.1b-1993
 * _POSIX_C_SOURCE == 199506L   1003.1c-1995, 1003.1i-1995,
 *				and the omnibus ISO/IEC 9945-1:1996
 * _POSIX_C_SOURCE == 200112L   1003.1-2001
 * _POSIX_C_SOURCE == 200809L   1003.1-2008
 * _POSIX_C_SOURCE == 202405L   1003.1-2024
 *
 * The POSIX spec implies a specific value for __ISO_C_VISIBLE, though
 * this may be overridden by the _ISOC99_SOURCE macro later.
 */
#ifdef _POSIX_C_SOURCE
# if (_POSIX_C_SOURCE - 0 >= 202405)
#  define __POSIX_VISIBLE	202405
#  define __ISO_C_VISIBLE	2017
# elif (_POSIX_C_SOURCE - 0 >= 200809)
#  define __POSIX_VISIBLE	200809
#  define __ISO_C_VISIBLE	1999
# elif (_POSIX_C_SOURCE - 0 >= 200112)
#  define __POSIX_VISIBLE	200112
#  define __ISO_C_VISIBLE	1999
# elif (_POSIX_C_SOURCE - 0 >= 199506)
#  define __POSIX_VISIBLE	199506
#  define __ISO_C_VISIBLE	1990
# elif (_POSIX_C_SOURCE - 0 >= 199309)
#  define __POSIX_VISIBLE	199309
#  define __ISO_C_VISIBLE	1990
# elif (_POSIX_C_SOURCE - 0 >= 2)
#  define __POSIX_VISIBLE	199209
#  define __ISO_C_VISIBLE	1990
# else
#  define __POSIX_VISIBLE	199009
#  define __ISO_C_VISIBLE	1990
# endif
#elif defined(_POSIX_SOURCE)
# define __POSIX_VISIBLE	198808
#  define __ISO_C_VISIBLE	0
#endif

/*
 * _ANSI_SOURCE means to expose ANSI C89 interfaces only.
 * If the user defines it in addition to one of the POSIX or XOPEN
 * macros, assume the POSIX/XOPEN macro(s) should take precedence.
 */
#if defined(_ANSI_SOURCE) && !defined(__POSIX_VISIBLE) && \
    !defined(__XPG_VISIBLE)
# define __POSIX_VISIBLE	0
# define __XPG_VISIBLE		0
# define __ISO_C_VISIBLE	1990
#endif

/*
 * _ISOC99_SOURCE, _ISOC11_SOURCE, __STDC_VERSION__, and __cplusplus
 * override any of the other macros since they are non-exclusive.
 */
#if defined(_ISOC11_SOURCE) || \
    (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112) || \
    (defined(__cplusplus) && __cplusplus >= 201703)
# undef __ISO_C_VISIBLE
# define __ISO_C_VISIBLE	2011
#elif defined(_ISOC99_SOURCE) || \
    (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901) || \
    (defined(__cplusplus) && __cplusplus >= 201103)
# undef __ISO_C_VISIBLE
# define __ISO_C_VISIBLE	1999
#endif

/*
 * Finally deal with BSD-specific interfaces that are not covered
 * by any standards.  We expose these when none of the POSIX or XPG
 * macros is defined or if the user explicitly asks for them.
 */
#if !defined(_BSD_SOURCE) && \
   (defined(_ANSI_SOURCE) || defined(__XPG_VISIBLE) || defined(__POSIX_VISIBLE))
# define __BSD_VISIBLE		0
#endif

/*
 * Default values.
 */
#ifndef __XPG_VISIBLE
# define __XPG_VISIBLE		800
#endif
#ifndef __POSIX_VISIBLE
# define __POSIX_VISIBLE	202405
#endif
#ifndef __ISO_C_VISIBLE
# define __ISO_C_VISIBLE	2017
#endif
#ifndef __BSD_VISIBLE
# define __BSD_VISIBLE		1
#endif

#endif /* !_SYS_CDEFS_H_ */
