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
#include <stdexcept>

#include "rgb2yuv.hpp"
#include "rgb2yuv_decoder.hpp"
#include "rgb2yuv_utils.hpp"
#include "rgb2yuv_utils_asm.hpp"

namespace rgb2yuv
{

void Context::init()
{
    // TODO
}

Context::~Context()
{
    // TODO
}

void Context::deinit()
{
    // TODO
}

} // namespace rgb2yuv

int main(int argc, char **argv)
{

    // Debug code for testing.
    // TODO: Remove in final version
#if 0
    try
    {
        const rgb2yuv::utils::InputArguments args { rgb2yuv::utils::InputParser::parseAndVerifyArgs(argc, argv) };
        rgb2yuv::Decoder decoder(args.inputFile, args.inputFileFormat, args.inputColorFormat);
        decoder.init();
        auto decodedData { decoder.decode() };
        auto outputStream { std::fstream(args.outputFile, std::ios::out | std::ios::binary) };
        if (!outputStream.is_open()) {
            throw std::invalid_argument("Failed to create output file");
        }
        for (const uint8_t value : decodedData) {
            outputStream << value;
        }
        decoder.deinit();
    }
    catch (std::invalid_argument& e)
    {
        std::cerr << "rgb2yuv: FATAL EXCEPTION: " << e.what() << std::endl;
        return -1;
    }
#endif
    return 0;
}

