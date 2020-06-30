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

// clang-format off

#ifndef _TRANSPORT_PLATFORM_SOCKET_H_
#  define _TRANSPORT_PLATFORM_SOCKET_H_

#ifdef _WIN32
#  include <winsock2.h>
#  define THRX_GET_SOCKET_ERROR ::WSAGetLastError()
#  define THRX_ERRNO (*_errno())
#  define THRX_EINPROGRESS WSAEINPROGRESS
#  define THRX_EAGAIN WSAEWOULDBLOCK
#  define THRX_EINTR WSAEINTR
#  define THRX_ECONNRESET WSAECONNRESET
#  define THRX_ENOTCONN WSAENOTCONN
#  define THRX_ETIMEDOUT WSAETIMEDOUT
#  define THRX_EWOULDBLOCK WSAEWOULDBLOCK
#  define THRX_EPIPE WSAECONNRESET
#  define THRX_NO_SOCKET_CACHING SO_EXCLUSIVEADDRUSE
#  define THRX_SOCKET SOCKET
#  define THRX_INVALID_SOCKET INVALID_SOCKET
#  define THRX_SOCKETPAIR thrx_socketpair
#  define THRX_FCNTL thrx_fcntl
#  define THRX_O_NONBLOCK 1
#  define THRX_F_GETFL 0
#  define THRX_F_SETFL 1
#  define THRX_GETTIMEOFDAY thrx_gettimeofday
#  define THRX_CLOSESOCKET closesocket
#  define THRX_CLOSE _close
#  define THRX_OPEN _open
#  define THRX_FTRUNCATE _chsize_s
#  define THRX_FSYNC _commit
#  define THRX_LSEEK _lseek
#  define THRX_WRITE _write
#  define THRX_READ _read
#  define THRX_IOCTL_SOCKET ioctlsocket
#  define THRX_IOCTL_SOCKET_NUM_BYTES_TYPE u_long
#  define THRX_FSTAT _fstat
#  define THRX_STAT _stat
#  ifdef _WIN32_WCE
#    define THRX_GAI_STRERROR(...) thrx_wstr2str(gai_strerrorW(__VA_ARGS__))
#  else
#    define THRX_GAI_STRERROR gai_strerrorA
#  endif
#  define THRX_SSIZET ptrdiff_t
#  if (_MSC_VER < 1900)
#    define THRX_SNPRINTF _snprintf
#  else
#    define THRX_SNPRINTF snprintf
#  endif
#  define THRX_SLEEP_SEC thrx_sleep
#  define THRX_SLEEP_USEC thrx_usleep
#  define THRX_TIMESPEC thrx_timespec
#  define THRX_CTIME_R thrx_ctime_r
#  define THRX_POLL thrx_poll
#  if WINVER <= 0x0502 //XP, Server2003
#    define THRX_POLLFD  thrx_pollfd
#    define THRX_POLLIN  0x0300
#    define THRX_POLLOUT 0x0010
#  else //Vista, Win7...
#    define THRX_POLLFD  pollfd
#    define THRX_POLLIN  POLLIN
#    define THRX_POLLOUT POLLOUT
#  endif //WINVER
#  define THRX_SHUT_RDWR SD_BOTH
#  if !defined(AI_ADDRCONFIG)
#    define AI_ADDRCONFIG 0x00000400
#  endif
#else //not _WIN32
#  include <errno.h>
#  define THRX_GET_SOCKET_ERROR errno
#  define THRX_ERRNO errno
#  define THRX_EINTR       EINTR
#  define THRX_EINPROGRESS EINPROGRESS
#  define THRX_ECONNRESET  ECONNRESET
#  define THRX_ENOTCONN    ENOTCONN
#  define THRX_ETIMEDOUT   ETIMEDOUT
#  define THRX_EWOULDBLOCK EWOULDBLOCK
#  define THRX_EAGAIN      EAGAIN
#  define THRX_EPIPE       EPIPE
#  define THRX_NO_SOCKET_CACHING SO_REUSEADDR
#  define THRX_SOCKET int
#  define THRX_INVALID_SOCKET (-1)
#  define THRX_SOCKETPAIR socketpair
#  define THRX_FCNTL fcntl
#  define THRX_O_NONBLOCK O_NONBLOCK
#  define THRX_F_GETFL F_GETFL
#  define THRX_F_SETFL F_SETFL
#  define THRX_GETTIMEOFDAY gettimeofday
#  define THRX_CLOSESOCKET close
#  define THRX_CLOSE close
#  define THRX_OPEN open
#  define THRX_FTRUNCATE ftruncate
#  define THRX_FSYNC fsync
#  define THRX_LSEEK lseek
#  define THRX_WRITE write
#  define THRX_READ read
#  define THRX_IOCTL_SOCKET ioctl
#  define THRX_IOCTL_SOCKET_NUM_BYTES_TYPE int
#  define THRX_STAT stat
#  define THRX_FSTAT fstat
#  define THRX_GAI_STRERROR gai_strerror
#  define THRX_SSIZET ssize_t
#  define THRX_SNPRINTF snprintf
#  define THRX_SLEEP_SEC sleep
#  define THRX_SLEEP_USEC usleep
#  define THRX_TIMESPEC timespec
#  define THRX_CTIME_R ctime_r
#  define THRX_POLL poll
#  define THRX_POLLFD  pollfd
#  define THRX_POLLIN  POLLIN
#  define THRX_POLLOUT POLLOUT
#  define THRX_SHUT_RDWR SHUT_RDWR
#endif

#endif // _TRANSPORT_PLATFORM_SOCKET_H_
