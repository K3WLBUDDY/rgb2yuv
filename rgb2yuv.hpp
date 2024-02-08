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
    class context
    {
        private:
        const bool supportsSSE { false }; ///< Status of SSE support on CPU (TODO)
        const bool supportsMMX { false }; ///< Status of MMX support on CPU (TODO)
        const bool supportsAVX { false }; ///< Status of AVX support on CPU (TODO)
        const bool supportsAVX2 { false }; ///< Status of AVX2 support on CPU (TODO
        const bool supportsAVX512 { false }; ///< Status of AVX512 support on CPU (TODO)
        // Mandatory arguments
        const std::string inputFile; ///< Input file to be converted
        const std::string outputFile; ///< Output file for storing converted data
        const utils::colorFormat inputColorFormat; ///< Color format of the data present in the input file
        const utils::colorFormat outputColorFormat; ///< Color format of the data to be written to the output file
        const utils::fileFormat inputFileFormat; ///< File format of the input file
        const utils::fileFormat outputFileFormat; ///< File format of the output file
        // Optional arguments
        uint32_t numThreads; ///< Number of threads to be used for conversion
        bool disableSimd; ///< Specifies if SIMD can be used during conversion

        public:
        context();
        bool init();
        ~context();
        bool deinit();
    };
} // namespace rgb2yuv
