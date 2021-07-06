#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <limits>

enum class Pages
{
    p_PagesDay = 1,
    p_Sum,
    p_Calculate,
    p_exit = 4,
};

struct HowManyPages
{
    std::string date;
    int pages = 0;
    int suma = 0;
    void enterdata();
    void enterTitle();
    void SaveToFile(HowManyPages savedate,std::string tit);
};

void sum();
void menu();
std::istream &operator>>(std::istream &in, Pages &enter);

// int extract_pages(const std::string &line); 