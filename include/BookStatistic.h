#pragma once
#include <iostream>

class BookStatistic
{
public:
    std::string DateOfReading;
    int NumberOfPagesRead = 0;
    int SumPages = 0;
    void enterdata();
    void sum() const;
    std::string enterTitle() const;
    void SaveToFile(const std::string &BookTitle) const;
};

void menu();

