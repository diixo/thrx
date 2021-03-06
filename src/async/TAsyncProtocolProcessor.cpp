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

#include "TAsyncProtocolProcessor.h"

// TODO:
//#include "../transport/TBufferTransports.h"

using thrx::transport::TBufferBase;
using thrx::protocol::TProtocol;

namespace thrx {
namespace async {


/* TODO:
void TAsyncProtocolProcessor::process(std::function<void(bool healthy)> _return,
                                      std::shared_ptr<TBufferBase> ibuf,
                                      std::shared_ptr<TBufferBase> obuf)
{
  std::shared_ptr<TProtocol> iprot(pfact_->getProtocol(ibuf));
  std::shared_ptr<TProtocol> oprot(pfact_->getProtocol(obuf));
  return underlying_
      ->process(std::bind(&TAsyncProtocolProcessor::finish,
                                             _return,
                                             oprot,
                                             std::placeholders::_1),
                iprot,
                oprot);
}
*/

/* static */ 
void TAsyncProtocolProcessor::finish(
    std::function<void(bool healthy)> _return,
    std::shared_ptr<TProtocol> oprot,
    bool healthy) 
{
  (void)oprot;
  // This is a stub function to hold a reference to oprot.
  return _return(healthy);
}
}
}   // thrx
