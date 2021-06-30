#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <limits>

enum class Pages
{
    p_PagesDay = 1,
    p_Sum,
    p_exit = 3,
};

struct HowManyPages
{
    std::string date;
    int pages = 0;
    int suma = 0;
    void enterdata();
    HowManyPages SaveToFile(HowManyPages savedate);
};

void sum();
void menu();
std::istream &operator>>(std::istream &in, Pages &enter);

// int extract_pages(const std::string &line); 