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

#include <iostream>
#include "rgb2yuv_decoder.hpp"

namespace rgb2yuv
{

void Decoder::init()
{
    if (!isSupported(m_inputFileFormat)) {
        throw std::invalid_argument("Input file format not supported for decoding!");
    }

    if (!isSupported(m_inputColorFormat)) {
        throw std::invalid_argument("Input color format not supported for decoding!");
    }

    m_inputFileStream = std::fstream(m_inputFile, std::ios::in);
    if (!m_inputFileStream.is_open()) {
        throw std::invalid_argument("Failed to open input file");
    }
}

void Decoder::deinit()
{
    // TODO
}

std::vector<std::uint8_t>& Decoder::decode()
{
    try
    {
        switch (m_inputFileFormat)
        {
            case(utils::FileFormat::ppm):
                decodePpm();
                break;
            case(utils::FileFormat::raw):
                decodeRaw();
                break;
            default:
                // Unreachable. Do nothing
                break;
        }
        return m_decodedData;
    }
    catch(...)
    {
        std::cerr << "Decoding failed\n";
        throw;
    }
}

void Decoder::decodePpm()
{
    std::uint32_t width { 0U };
    std::uint32_t height { 0U };
    // Verify PPM header
    std::string ppmMagic { };
    std::string expectedPpmMagic { "P3" };
    std::getline(m_inputFileStream, ppmMagic);
    if (ppmMagic != expectedPpmMagic) {
        throw std::invalid_argument("Unsupported input PPM file. Only RGB PPM files (P3) are supported");
    }
    m_inputFileStream << height;
    std::cout << "H: " << height << " W: " << width << "\n";
    std::getline(m_inputFileStream, ppmMagic);
}

void Decoder::decodeRaw()
{
    // TODO
}

bool Decoder::isSupported(utils::FileFormat fileFormat) noexcept
{
    bool ret { false };

    switch(fileFormat)
    {
        case(utils::FileFormat::ppm):
        case(utils::FileFormat::raw):
            ret = true;
            break;
        default:
            // Do nothing
            break;
    }

    return ret;
}

bool Decoder::isSupported(utils::ColorFormat colorFormat) noexcept
{
    bool ret { false };

    switch(colorFormat)
    {
        case(utils::ColorFormat::rgb888):
        case(utils::ColorFormat::rgba8888):
            ret = true;
            break;
        default:
            // Do nothing
            break;
    }

    return ret;
}

} // namespace rgb2yuv

