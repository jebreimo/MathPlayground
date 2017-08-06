//****************************************************************************
// Copyright © 2017 Jan Erik Breimo. All rights reserved.
// Created by Jan Erik Breimo on 2017-08-06.
//
// This file is distributed under the BSD License.
// License text is included with the source distribution.
//****************************************************************************
#pragma once
#include <iostream>
#include "Factorize.hpp"

template <typename T, typename It>
std::pair<T, T> findBestFactorsRecursive(
        T n, std::pair<T, T> bestFactors,
        T squareRoot,
        T factor,
        It firstRemainingFactor,
        It lastRemainingFactor)
{
    auto bestDiff = std::abs(bestFactors.first - bestFactors.second);
    auto otherFactor = n / factor;
    auto diff = std::abs(factor - otherFactor);
    if (diff < bestDiff)
        bestFactors = {factor, otherFactor};
    if (factor > squareRoot)
        return bestFactors;
    T newFactor = 0;
    for (auto it = firstRemainingFactor; it != lastRemainingFactor; ++it)
    {
        if (*it != newFactor)
        {
            newFactor = *it;
            bestFactors = findBestFactorsRecursive(n, bestFactors, squareRoot,
                                                   factor * newFactor,
                                                   it + 1,
                                                   lastRemainingFactor);
        }
    }
    return bestFactors;
}

template <typename T>
std::pair<T, T> findBestFactors(T n)
{
    if (n == 0)
        return {0, 0};
    auto m = std::abs(n);
    auto squareRoot = T(std::ceil(std::sqrt(m)));
    if (squareRoot * squareRoot == m)
        return {squareRoot, n / squareRoot};
    auto factors = factorize(std::abs(m));
    auto result = findBestFactorsRecursive(m, {m, 1}, squareRoot,
                                           factors.back(),
                                           factors.rbegin() + 1,
                                           factors.rend());

    if (n > 0)
        return result;
    else
        return {result.first, -result.second};
}
