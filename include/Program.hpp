#pragma once
#include "IProgram.hpp"
#include "IBookStatistic.hpp"
#include "IFile.hpp"
#include <memory>

class Program : public IProgram
{
private:
    std::shared_ptr<IBookStatistic> bookStats;
    std::shared_ptr<IFile> file;

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
    Program(std::shared_ptr<IBookStatistic>, std::shared_ptr<IFile>);

    auto run() -> void override;
};
