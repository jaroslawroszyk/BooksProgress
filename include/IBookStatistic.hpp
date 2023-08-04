#pragma once
class BookStatistic;

class IBookStatistic
{
public:
    virtual ~IBookStatistic() {}
    virtual void enterData() = 0;
    virtual BookStatistic calculateTotalPagesRead() const = 0;
};
