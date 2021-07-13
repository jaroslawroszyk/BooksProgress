#pragma once
#include <fstream>

enum class ProgramMode
{
    p_PagesDay = 1,
    p_Sum = 2 ,
    p_Show = 3,
    p_delete = 4,
    p_Calculate = 5,
    p_exit = 6,
};
 

std::istream &operator>>(std::istream &in, ProgramMode &enter);