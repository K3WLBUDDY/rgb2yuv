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

#pragma once

#include <array>
#include <cstdint>

namespace rgb2yuv
{

class utils_asm
{
    public:

    // Variables
    static constexpr std::uint32_t ct_numCpuIdRegisters { 4U }; ///< Number of values returned by @ref utils_asm::cpuId
    static constexpr std::uint32_t ct_eax { 0U }; ///< Index for accessing EAX in the return value of @ref utils_asm::cpuId
    static constexpr std::uint32_t ct_ebx { 1U }; ///< Index for accessing EBX in the return value of @ref utils_asm::cpuId
    static constexpr std::uint32_t ct_ecx { 2U }; ///< Index for accessing ECX in the return value of @ref utils_asm::cpuId
    static constexpr std::uint32_t ct_edx { 3U }; ///< Index for accessing EAD in the return value of @ref utils_asm::cpuId

    // Public member functions

    ///
    /// @brief Invokes the CPUID assembly function and returns values stored
    ///        in registers EAX, EBX, ECX and EDX (in that order)
    ///
    /// @param[in]     value to be stored in EAX when CPUID asm gets executed
    /// @param[in]     value to be stored in ECX when CPUID asm gets executed
    /// @param[in/out] @ref utils_asm::ct_numCpuIdRegisters sized std::array
    ///                containing the values of EAX, EBX, ECX and EDX after execution of CPUID asm
    ///
    /// @return None
    ///
    static void cpuId(const std::uint32_t inputEAX,
                      const std::uint32_t inputECX,
                      std::array<std::uint32_t , ct_numCpuIdRegisters> &out) noexcept;
};

} // namespace rgb2yuv
