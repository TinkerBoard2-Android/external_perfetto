/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "tracing/src/test/test_shared_memory.h"

#include <string.h>

#include "cpp_common/base.h"

namespace perfetto {

TestSharedMemory::TestSharedMemory(size_t size) {
  mem_.reset(new char[size]);
  memset(mem_.get(), 0, size);
  size_ = size;
}

TestSharedMemory::~TestSharedMemory() {}

TestSharedMemory::Factory::~Factory() {}

std::unique_ptr<SharedMemory> TestSharedMemory::Factory::CreateSharedMemory(
    size_t size) {
  return std::unique_ptr<SharedMemory>(new TestSharedMemory(size));
}

}  // namespace perfetto