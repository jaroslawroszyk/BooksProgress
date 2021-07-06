#pragma once
#include <iostream>

class HowManyPages
{
public:
    std::string DateOfReading;
    int NumberOfPagesRead = 0;
    int SumPages = 0;
    void enterdata();
    void sum(); 
    std::string  enterTitle() const;
    static void SaveToFile(HowManyPages &savedate, std::string &tit);
    
};

void menu();
int calc();

