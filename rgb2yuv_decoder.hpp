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

#include <fstream>
#include <vector>

#include "rgb2yuv_utils.hpp"

namespace rgb2yuv
{

class Decoder
{
    private:
        const std::string m_inputFile; ///< Input file path
        const utils::FileFormat m_inputFileFormat; ///< Format of @ref Decoder::m_inputFile
        const utils::ColorFormat m_inputColorFormat; ///< Format of the color data in @ref Decoder::m_inputFile
        std::vector<std::uint8_t> m_decodedData { }; ///< Container for the decoded color data in RGBA8888 form
        std::fstream m_inputFileStream; ///< Input stream to @ref Decoder::m_inputFile

        ///
        /// @brief Extract color data from a PPM image file
        ///
        /// Design: TODO
        ///
        void decodePpm();

        ///
        /// @brief Extract color data from a RAW image file
        ///
        /// Design: TODO
        ///
        void decodeRaw();

        ///
        /// @brief Check if the input file format is supported for decoding
        ///
        /// Design:
        /// -# Return true for the following values of @p fileFormat:
        ///    -# @ref utils::FileFormat::ppm
        ///    -# @ref utils::FileFormat::raw
        /// -# Return false for any other values of @p fileFormat
        ///
        /// @returns @true if @p fileFormat is supported for decoding, else @false
        ///
        bool isSupported(utils::FileFormat fileFormat) noexcept;

        ///
        /// @brief Check if the color format of the input file format is supported for decoding
        ///
        /// Design:
        /// -# Return true for the following values of @p colorFormat:
        ///    -# @ref utils::ColorFormat::rgb888
        ///    -# @ref utils::ColorFormat::rgba8888
        /// -# Return false for any other values of @p colorFormat
        ///
        /// @returns @true if @p colorFormat is supported for decoding, else @false
        ///
        bool isSupported(utils::ColorFormat colorFormat) noexcept;
    public:
        ///
        /// @brief Sole parameterized constructor
        ///
        /// Design:
        /// -# Assign the input parameters as below:
        ///    -# @p inputFile - @ref Decoder::m_inputFile
        ///    -# @p inputFileFormat - @ref Decoder::m_inputFileFormat
        ///    -# @p inputColorFormat - @ref Decoder::m_inputColorFormat
        ///
        Decoder(const std::string &inputFile, const utils::FileFormat inputFileFormat,
                const utils::ColorFormat inputColorFormat) : m_inputFile(inputFile),
                                                             m_inputFileFormat(inputFileFormat),
                                                             m_inputColorFormat(inputColorFormat)
        {
        }

        ///
        /// @brief Performs initialization steps of @ref Decoder that may fail
        ///
        /// @throws std::invalid_argument if @ref Decoder::m_inputFileFormat or @ref Decoder::m_inputColorFormat
        ///         is not supported by @ref Decoder
        /// Design:
        /// -# Invoke @ref Decoder::isSupported on @ref Decoder::m_inputFileFormat
        ///    -# Throw std::invalid_argument if @false is returned
        /// -# Invoke @ref Decoder::isSupported on @ref Decoder::m_inputColorFormat
        ///    -# Throw std::invalid_argument if @false is returned
        /// -# Open a file stream to @ref Decoder::m_inputFile
        /// -# Check if the file is opened
        ///    -# Throw std::invalid_argument if check fails
        ///
        void init();
        void deinit();
        std::vector<std::uint8_t> &decode();
};

} // namespace rgb2yuv
