#pragma once
#include <iostream>

template<int N>
class Template
{
public:
    Template() = default;

    static constexpr int value = N * Template<N -1>::value;
};

template<>
class Template<1>
{
public:
    Template() = default;
    static constexpr int value = 1;
};


