// Copyright (c) 2024 Sruthik P
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <intrin.h>

#include "rgb2yuv_utils_asm.hpp"

namespace rgb2yuv
{

void utils_asm::cpuId(const std::uint32_t inputEAX,
                      const std::uint32_t inputECX,
                      std::array<std::uint32_t, ct_numCpuIdRegisters> &out) noexcept
{
    int32_t cpuInfo[ct_numCpuIdRegisters] { };
    __cpuidex(cpuInfo, inputEAX, inputECX);
    for (std::uint32_t idx { 0U }; idx < ct_numCpuIdRegisters; ++idx)
    {
        out[idx] = static_cast<std::uint32_t>(cpuInfo[idx]);
    }
}

} // namespace rgb2yuv
