#pragma once
#include <string>

class BookStatistic;

class IBookStatistic
{
public:
    auto saveToFile(const std::string&) const -> void;

    virtual ~IBookStatistic() {}
    virtual void enterData() = 0;
    virtual BookStatistic calculateTotalPagesRead(const std::string&) const = 0;
};
