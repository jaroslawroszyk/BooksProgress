#include "ProgramMode.hpp"

std::istream& operator>>(std::istream& in, ProgramMode& enter)
{
    int int_entry;
    enter = (in >> int_entry) ? static_cast<ProgramMode>(int_entry) : ProgramMode::p_exit;
    return in;
}
