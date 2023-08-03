#pragma once
#include "BookStatistic.hpp"
#include "IProgram.hpp"

class Program : public IProgram
{
private:
    BookStatistic bookStats;
    auto calculatePages() -> int;
    auto clearConsole() -> void;
    auto showFilesTxt() -> void;
    auto deleteFile() -> void;
    auto showContent() -> void;

public:
    auto run() -> void override;
};