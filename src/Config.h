/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/* config.h generated by CMake from config.h.in */

#ifndef CONFIG_H
#define CONFIG_H

/************************** DEFINES *************************/

/* Define if the AI_ADDRCONFIG symbol is unavailable */
//#cmakedefine AI_ADDRCONFIG 0

/* Possible value for SIGNED_RIGHT_SHIFT_IS */
/* TODO: This is just set to 1 for the moment
   port the macro aclocal/ax_signed_right_shift.m4 to CMake to make this work */
#define ARITHMETIC_RIGHT_SHIFT 1

/* Indicates the effect of the right shift operator on negative signed
   integers */
/* TODO: This is just set to 1 for the moment */
#define SIGNED_RIGHT_SHIFT_IS 1

/* Use *.h extension for parser header file */
/* TODO: This might now be necessary anymore as it is set only for automake < 1.11
   see: aclocal/ac_prog_bison.m4 */
//#cmakedefine BISON_USE_PARSER_H_EXTENSION 1

/* Define to 1 if strerror_r returns char *. */
//#cmakedefine STRERROR_R_CHAR_P 1


/************************** HEADER FILES *************************/

/* Define to 1 if you have the <arpa/inet.h> header file. */
#include <arpa/inet.h>
#cmakedefine HAVE_ARPA_INET_H 1

/* Define to 1 if you have the <fcntl.h> header file. */
#include <fcntl.h>
#cmakedefine HAVE_FCNTL_H 1

/* Define to 1 if you have the <inttypes.h> header file. */
#include <inttypes.h>
#cmakedefine HAVE_INTTYPES_H 1

/* Define to 1 if you have the <netdb.h> header file. */
#include <netdb.h>
#cmakedefine HAVE_NETDB_H 1

/* Define to 1 if you have the <netinet/in.h> header file. */
#include <netinet/in.h>
#cmakedefine HAVE_NETINET_IN_H 1

/* Define to 1 if you have the <signal.h> header file. */
#include <signal.h>
#cmakedefine HAVE_SIGNAL_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#include <stdint.h>
#cmakedefine HAVE_STDINT_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#include <unistd.h>
#cmakedefine HAVE_UNISTD_H 1

/* Define to 1 if you have the <pthread.h> header file. */
#include <pthread.h>
#cmakedefine HAVE_PTHREAD_H 1

/* Define to 1 if you have the <sys/ioctl.h> header file. */
#include <sys/ioctl.h>
#cmakedefine HAVE_SYS_IOCTL_H 1

/* Define to 1 if you have the <sys/param.h> header file. */
#include <sys/param.h>
#cmakedefine HAVE_SYS_PARAM_H 1

/* Define to 1 if you have the <sys/resource.h> header file. */
#include <sys/resource.h>
#cmakedefine HAVE_SYS_RESOURCE_H 1

/* Define to 1 if you have the <sys/socket.h> header file. */
#include <sys/socket.h>
#cmakedefine HAVE_SYS_SOCKET_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#include <sys/stat.h>
#cmakedefine HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/un.h> header file. */
#include <sys/un.h>
#cmakedefine HAVE_SYS_UN_H 1

/* Define to 1 if you have the <poll.h> header file. */
#include <poll.h>
#cmakedefine HAVE_POLL_H 1

/* Define to 1 if you have the <sys/poll.h> header file. */
#include <sys/poll.h>
#cmakedefine HAVE_SYS_POLL_H 1

/* Define to 1 if you have the <sys/select.h> header file. */
#include <sys/select.h>
#cmakedefine HAVE_SYS_SELECT_H 1

/* Define to 1 if you have the <sys/time.h> header file. */
#include <sys/time.h>
#cmakedefine HAVE_SYS_TIME_H 1

/* Define to 1 if you have the <sched.h> header file. */
#include <sched.h>
#cmakedefine HAVE_SCHED_H 1

/* Define to 1 if you have the <strings.h> header file. */
#include <strings.h>
#define HAVE_STRINGS_H 1

#endif
