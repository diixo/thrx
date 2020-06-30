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

#ifndef _CONCURRENCY_EXCEPTION_H_
#define _CONCURRENCY_EXCEPTION_H_ 1

#include <exception>

#include "../Thrx.h"

namespace thrx {

namespace concurrency {

class NoSuchTaskException : public thrx::TException 
{};

class UncancellableTaskException : public thrx::TException 
{};

class InvalidArgumentException : public thrx::TException 
{};

class IllegalStateException : public thrx::TException 
{
public:
  IllegalStateException() = default;
  IllegalStateException(const std::string& message) 
     : TException(message) 
  {}
};

class TimedOutException : public thrx::TException 
{
public:
  TimedOutException() 
     : TException("TimedOutException")
  {};

  TimedOutException(const std::string& message) 
     : TException(message) 
  {}
};

class TooManyPendingTasksException : public thrx::TException 
{
public:
  TooManyPendingTasksException() 
     : TException("TooManyPendingTasksException")
  {};

  TooManyPendingTasksException(const std::string& message) 
     : TException(message) 
  {}
};

class SystemResourceException : public thrx::TException {
public:
  SystemResourceException() = default;

  SystemResourceException(const std::string& message) 
     : TException(message) {}
};

}
}

#endif // #ifndef _CONCURRENCY_EXCEPTION_H_
