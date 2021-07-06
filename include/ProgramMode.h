#pragma once
#include <fstream>

enum class ProgramMode
{
    p_PagesDay = 1,
    p_Sum = 2 ,
    p_Show = 3,
    p_Calculate = 4,
    p_exit = 5,
};
 

std::istream &operator>>(std::istream &in, ProgramMode &enter);