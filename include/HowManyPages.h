#pragma once
#include <iostream>

class HowManyPages
{
public:
    std::string DateOfReading;
    int NumberOfPagesRead = 0;
    int SumPages = 0;
    void enterdata();
    void sum() const; 
    std::string  enterTitle() const;
    static void SaveToFile(const HowManyPages &savedate, std::string &BookTitle);
};

void menu();
int calc();

