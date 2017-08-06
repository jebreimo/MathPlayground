//****************************************************************************
// Copyright © 2017 Jan Erik Breimo. All rights reserved.
// Created by Jan Erik Breimo on 2017-08-06.
//
// This file is distributed under the BSD License.
// License text is included with the source distribution.
//****************************************************************************
#include "ClosestTwoFactors.hpp"

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        std::cerr << "Usage: " << argv[0] << " <number> [number ...]\n";
        return 1;
    }

    for (int i = 1; i < argc; ++i)
    {
        auto n = strtoll(argv[i], nullptr, 0);
        auto factors = findBestFactors(n);
        std::cout << n << " = " << factors.first << " * " << factors.second
                  << std::endl;
    }

    return 0;
}
