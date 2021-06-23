#pragma once
#include <iostream>
#include <string>
#include <fstream>

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
    int suma=0;
    HowManyPages enterdata();
    HowManyPages SaveToFile(HowManyPages savedate);
    int sum(HowManyPages k);
    // HowManyPages show();
};
// # g++ main.cpp pages.cpp -o Howmany
// void sum(); //a function that sums up all the page counts in a file

void menu();
std::istream &operator>>(std::istream &in, Pages &enter);

// void EnterData();