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

#ifndef _WINDOWS_GETTIMEOFDAY_H_
#define _WINDOWS_GETTIMEOFDAY_H_

#if defined(_MSC_VER) && (_MSC_VER > 1200)
#pragma once
#endif // _MSC_VER

#ifndef _WIN32
#error This is a MSVC header only.
#endif

#include "../Thrx-config.h"
#include <time.h>

struct thrx_timespec
{
  int64_t tv_sec;
  int64_t tv_nsec;
};

int thrx_gettimeofday(struct timeval* tv, struct timezone* tz);
int thrx_sleep(unsigned int seconds);
int thrx_usleep(unsigned int micro_seconds);
char* thrx_ctime_r(const time_t* _clock, char* _buf);

#endif // _WINDOWS_GETTIMEOFDAY_H_
