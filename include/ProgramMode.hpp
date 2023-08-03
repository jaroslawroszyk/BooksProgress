#pragma once
#include <fstream>

enum class ProgramMode
{
    p_numberOfPagesPerDay = 1,
    p_sumOfReadPagesInBook = 2,
    p_showAvailableFiles = 3,
    p_showContentOfFile = 4,
    p_deleteFile = 5,
    p_calculatePages = 6,
    p_exit = 7,
};

std::istream& operator>>(std::istream&, ProgramMode&);
