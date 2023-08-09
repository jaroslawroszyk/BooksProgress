#pragma once
#include "IBookStatistic.hpp"
#include <iostream>

class BookStatistic : public IBookStatistic
{
private:
    std::string dateOfReading;
    int numberOfPagesRead = 0;
    int sumPages = 0;

    auto enterTitle() const->std::string;
public:
    auto saveToFile(const std::string& BookTitle) const -> void;
    BookStatistic() = default;
    void enterData() override;
    BookStatistic calculateTotalPagesRead(const std::string& fileName) const override;


    int getSumPages() const;
};
