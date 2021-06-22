#pragma once
#include <iostream>
#include <string>
#include <fstream>

struct HowManyPages
{
    std::string date;
    int pages;
    HowManyPages enterdata();
    HowManyPages SaveToFile(HowManyPages savedate);

};



enum class Pages
{
    p_PagesDay = 1,
    p_Sum,
    p_exit = 3,
};

void menu();
std::istream &operator>>(std::istream &in, Pages &enter);


