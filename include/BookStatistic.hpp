#pragma once
#include <iostream>

class BookStatistic
{
private:
    std::string dateOfReading;
    int numberOfPagesRead = 0;
    int sumPages = 0;

    auto enterTitle() const->std::string;
    auto saveToFile(const std::string&) const -> void;

public:
    BookStatistic() = default;
    auto enterData() -> void;
    auto calculateTotalPagesRead() const -> void;
};