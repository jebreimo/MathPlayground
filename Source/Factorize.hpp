//****************************************************************************
// Copyright © 2017 Jan Erik Breimo. All rights reserved.
// Created by Jan Erik Breimo on 2017-08-05.
//
// This file is distributed under the BSD License.
// License text is included with the source distribution.
//****************************************************************************
#pragma once
#include <cmath>
#include <vector>

template <typename T>
std::vector<T> factorize(T n)
{
    std::vector<T> factors;
    factors.reserve(10);
    if (std::abs(n) < 2)
    {
        factors.push_back(n);
        return factors;
    }

    if (n < 0)
    {
        factors.push_back(-1);
        n = -n;
    }

    while (n % 2 == 0)
    {
        factors.push_back(2);
        n /= 2;
    }

    while (n % 3 == 0)
    {
        factors.push_back(3);
        n /= 3;
    }

    if (n != 1)
    {
        auto max = T(std::ceil(std::sqrt(n)));
        auto inc = 4;
        for (T i = 5; i <= max; i += inc)
        {
            if (n % i == 0)
            {
                do
                {
                    factors.push_back(i);
                    n /= i;
                } while (n % i == 0);
                if (n == 1)
                    break;
                max = T(std::ceil(std::sqrt(n)));
            }
            inc ^= 6;
        }
        if (n != 1)
            factors.push_back(n);
    }

    return factors;
}
