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

#include "rgb2yuv_utils.hpp"

namespace rgb2yuv
{

// Forward declare few classes
class Converter;
class Decoder;
class Encoder;

class Context
{
    private:
    const bool m_supportsSSE { false }; ///< Status of SSE support on CPU (TODO)
    const bool m_supportsMMX { false }; ///< Status of MMX support on CPU (TODO)
    const bool m_supportsAVX { false }; ///< Status of AVX support on CPU (TODO)
    const bool m_supportsAVX2 { false }; ///< Status of AVX2 support on CPU (TODO
    const bool m_supportsAVX512 { false }; ///< Status of AVX512 support on CPU (TODO)
    const utils::InputArguments m_inputArgs; ///< Input arguments to rgb2yuv
    Converter *m_converter { nullptr }; ///< Pointer to a @ref rgb2yuv::Converter instance
    Decoder *m_decoder { nullptr }; ///< Pointer to a @ref rgb2yuv::Decoder instance
    Encoder *m_encoder { nullptr }; ///< Pointer to a @ref rgb2yuv::Encoder instance

    public:
    ///
    /// @brief Sole parameterized constructor
    ///
    /// Design: TODO
    ///
    Context(const utils::InputArguments &inputArgs) : m_inputArgs(inputArgs)
    {
    };

    ///
    /// @brief Performs initialization of @ref rgb2yuv::Context that may fail
    ///
    /// Design: TODO
    ///
    void init();

    /// @brief Sole destructor
    ///
    /// Design: TODO
    ///
    ~Context();

    /// @brief Performs deinitialiazation of @ref rgb2yuv::Context that may fail
    ///
    /// Design: TODO
    ///
    void deinit();

    ///
    /// @brief Returns @ref utils::InputArguments containing the input arguments specified.
    ///
    /// Design: Return @ref rgb2yuv::Context::m_inputArgs
    ///
    /// @return Reference to @refrgb2yuv::Context::m_inputArgs
    ///
    const utils::InputArguments& getInputArguments() const noexcept
    {
        return m_inputArgs;
    }
};

} // namespace rgb2yuv
