#pragma once
#include <fstream>

enum class Pages
{
    p_PagesDay = 1,
    p_Sum,
    p_Calculate,
    p_exit = 4,
};

std::istream &operator>>(std::istream &in, Pages &enter);