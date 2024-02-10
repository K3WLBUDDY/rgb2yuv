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

#include "rgb2yuv_utils.hpp"

#include <iostream>

namespace rgb2yuv
{

namespace utils
{

void InputParser::printHelpMessage() noexcept
{
    std::cout << "\t RGB2YUV - Simple RGB to YUV image converter\n\n\n";
    std::cout << "Mandatory input arguments to be specified:\n\n";
    std::cout << "-inputFile:         Input file containing RGB data to be converted\n";
    std::cout << "-inputFileFormat:   Format of the input file\n";
    std::cout << "                    Valid values: c_header, ppm, raw\n";
    std::cout << "                    NOTE: Not all file formats may be supported for input file\n";
    std::cout << "-inputColorFormat:  Format of the color data in the input file\n";
    std::cout << "                    Valid values: rgb888, rgba8888, uyvy, yuv420_nv12, yuv444_packed,\n";
    std::cout << "                                  yuv444_planar, yuyv\n";
    std::cout << "                    NOTE: Not all color formats may be supported for input file\n";
    std::cout << "-outputFile :       Output file containing the converted YUV data\n";
    std::cout << "-outputFileFormat:  Format of the output file\n";
    std::cout << "                    Valid values: c_header, ppm, raw\n";
    std::cout << "                    NOTE: Not all file formats may be supported for output file\n";
    std::cout << "-outputColorFormat: Format of the color data in the input file\n";
    std::cout << "                    Valid values: rgb888, rgba8888, uyvy, yuv420_nv12, yuv444_packed,\n";
    std::cout << "                                  yuv444_planar, yuyv\n";
    std::cout << "                    NOTE: Not all color formats may be supported for output file\n";
    std::cout << "\nOptional input arguments:\n\n";
    std::cout << "-j:                 Number of threads to use for the conversion process\n";
    std::cout << "                    Default: Number of logical processors present\n";
    std::cout << "-disableSimd:       Disable any form of SIMD usage during the conversion process\n";
    std::cout << "-help:              Print this help message\n";
}

ColorFormat InputParser::toColorFormat(const std::string &inputString) noexcept
{
    ColorFormat ret { };

    if (inputString.empty()) {
        ret = ColorFormat::unspecified;
    } else if (inputString == "rgb888") {
        ret = ColorFormat::rgb888;
    } else if (inputString == "rgba8888") {
        ret = ColorFormat::rgba8888;
    } else if (inputString == "uyvy") {
        ret = ColorFormat::uyvy;
    } else if (inputString == "yuv420_nv12") {
        ret = ColorFormat::yuv420_nv12;
    } else if (inputString == "yuv444_packed") {
        ret = ColorFormat::yuv444_packed;
    } else if (inputString == "yuv444_planar") {
        ret = ColorFormat::yuv444_planar;
    } else if (inputString == "yuyv") {
        ret = ColorFormat::yuyv;
    } else {
        ret = ColorFormat::unrecognized;
    }

    return ret;
}

FileFormat InputParser::toFileFormat(const std::string &inputString) noexcept
{
    FileFormat ret { };

    if (inputString.empty()) {
        ret = FileFormat::unspecified;
    } else if (inputString == "c_header") {
        ret = FileFormat::c_header;
    } else if (inputString == "ppm") {
        ret = FileFormat::ppm;
    } else if (inputString == "raw") {
        ret = FileFormat::raw;
    } else {
        ret = FileFormat::unrecognized;
    }

    return ret;
}

utils::InputArguments InputParser::parseArgs(const std::int32_t argc, char **argv)
{
    utils::InputArguments ret { };

    for (std::uint32_t idx { 1U }; idx < static_cast<std::uint32_t>(argc); ++idx)
    {
        if (!strcmp(argv[idx], "-help")) {
            printHelpMessage();
        } else if (!strcmp(argv[idx], "-inputFile") && (idx != argc - 1U)) {
            ret.inputFile = argv[++idx];
        } else if (!strcmp(argv[idx], "-inputColorFormat") && (idx != argc - 1U)) {
            ret.inputColorFormat = toColorFormat(std::string(argv[++idx]));
        } else if (!strcmp(argv[idx], "-inputFileFormat") && (idx != argc - 1U)) {
            ret.inputFileFormat = toFileFormat(std::string(argv[++idx]));
        } else if (!strcmp(argv[idx], "-outputFile") && (idx != argc - 1U)) {
            ret.outputFile = argv[++idx];
        } else if (!strcmp(argv[idx], "-outputColorFormat") && (idx != argc - 1U)) {
            ret.outputColorFormat = toColorFormat(std::string(argv[++idx]));
        } else if (!strcmp(argv[idx], "-outputFileFormat") && (idx != argc - 1U)) {
            ret.outputFileFormat = toFileFormat(std::string(argv[++idx]));
        } else if (!strcmp(argv[idx], "-j") && (idx != argc - 1U)){
            ret.numThreads = strtol(argv[++idx], nullptr, 10U);
        } else if (!strcmp(argv[idx], "-disableSimd")) {
            ret.disableSimd = true;
        } else {
            throw std::invalid_argument("Unrecognized argument specified! Run with '-help' to see the list of accepted arguments.");
        }
    }

    return ret;
}

void InputParser::verifyArgs(const utils::InputArguments &args)
{
    if (args.inputFile.empty()) {
        throw std::invalid_argument("No input file specified!");
    }

    if (args.inputColorFormat == ColorFormat::unrecognized) {
        throw std::invalid_argument("Unrecognized input color format specified");
    }

    if (args.inputColorFormat == ColorFormat::unspecified) {
        throw std::invalid_argument("No input color format specified!");
    }

    if (args.inputFileFormat == FileFormat::unrecognized) {
        throw std::invalid_argument("Unrecognized input file format specified");
    }

    if (args.inputFileFormat == FileFormat::unspecified) {
        throw std::invalid_argument("No input file format specified");
    }

    if (args.outputFile.empty()) {
        throw std::invalid_argument("No output file specified!");
    }

    if (args.outputColorFormat == ColorFormat::unrecognized) {
        throw std::invalid_argument("Unrecognized output color format specified");
    }

    if (args.outputColorFormat == ColorFormat::unspecified) {
        throw std::invalid_argument("No output color format specified!");
    }

    if (args.outputFileFormat == FileFormat::unrecognized) {
        throw std::invalid_argument("Unrecognized output file format specified");
    }

    if (args.outputFileFormat == FileFormat::unspecified) {
        throw std::invalid_argument("No output file format specified");
    }
}

utils::InputArguments InputParser::parseAndVerifyArgs(std::int32_t argc, char **argv)
{
    try
    {
        utils::InputArguments args { parseArgs(argc, argv) };
        verifyArgs(args);

        return args;
    }
    catch (std::invalid_argument& e)
    {
        // Re-throw caught exception
        throw;
    }
}

} // namespace utils

} // namespace rgb2yuv

