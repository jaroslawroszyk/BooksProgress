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

    auto calculatePages() -> int;
    auto clearConsole() -> void;
    auto showFilesTxt() -> void;
    auto deleteFile() -> void;
    auto showContent() -> void;

public:
    Program(std::shared_ptr<IBookStatistic>, std::shared_ptr<IFile>);

    auto run() -> void override;
};
