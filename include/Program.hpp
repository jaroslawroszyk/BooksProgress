#pragma once
#include "IProgram.hpp"
#include "IBookStatistic.hpp"
#include <memory>

class Program : public IProgram
{
private:
    std::shared_ptr<IBookStatistic> bookStats;

    auto clearConsole() -> void;
    auto showFilesTxt() -> void;
    auto showContent() -> void;

    void handleNumberOfPagesPerDay();
    void handleSumOfReadPagesInBook();
    void handleShowAvailableFiles();
    void handleShowContentOfFile();
    void handleDeleteFile();
    void handleCalculatePages();

public:
    Program(std::shared_ptr<IBookStatistic>);
    auto run() -> void override;
};
