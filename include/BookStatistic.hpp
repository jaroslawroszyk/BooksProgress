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
    BookStatistic() = default;
    void enterData() override;
    auto saveToFile(const std::string& BookTitle) const -> void;
    BookStatistic calculateTotalPagesRead(const std::string& fileName) const override;
    int getSumPages() const;

    void setDateOfReading(const std::string& dateReading) { dateOfReading = dateReading; }
    void setNumberOfPagesRead(int numberOfPages) { numberOfPagesRead = numberOfPages; }
};
