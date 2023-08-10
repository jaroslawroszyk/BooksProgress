#include "BookStatistic.hpp"
#include "ProgramMode.hpp"
#include "Program.hpp"
#include <iostream>
#include <filesystem>
#include <memory>

Program::Program(std::shared_ptr<IBookStatistic> stats, std::shared_ptr<IFile> file)
    : bookStats(stats), file(file)
{
}

auto Program::clearConsole() -> void
{
#ifdef _WIN32
    int result = std::system("cls");
    (void)result;
#else
    int result = std::system("clear");
    (void)result;
#endif
}

auto Program::showFilesTxt() -> void
{
    for (auto& de : std::filesystem::directory_iterator("."))
    {
        if (de.is_regular_file() && de.path().string().ends_with(".txt"))
        {
            std::cout << de.path().filename() << '\n';
        }
    }
}

auto Program::showContent() -> void
{
    std::string nameFile{};
    std::cout << "Enter the name of the file you want to see the contents (without extension): ";
    std::cin >> nameFile;
    nameFile += ".txt";
    std::ifstream contentOfFile(nameFile);
    if (contentOfFile.is_open())
    {
        std::cout << contentOfFile.rdbuf();
    }
    contentOfFile.close();
}

auto showMenu() -> void
{
    std::cout << "[1] Enter day and number of pages next enter book's title (automatic save)\n";
    std::cout << "[2] Add up the number of pages from a given book \n";
    std::cout << "[3] Show available files \n";
    std::cout << "[4] Show the contents of the file \n";
    std::cout << "[5] Delete file\n";
    std::cout << "[6] Count how many pages you have read \n";
    std::cout << "[7] Exit \n";
}

auto Program::handleNumberOfPagesPerDay() -> void
{
    clearConsole();
    std::cout << "Enter the number of pages you read today: ";
    int pagesRead{ 0 };
    std::cin >> pagesRead;

    std::string title{};
    std::cout << "Enter the title of the book: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    std::ofstream outFile(title + ".txt");
    outFile << pagesRead;
    outFile.close();

    std::cout << "Data saved." << std::endl;
}

auto Program::handleSumOfReadPagesInBook()-> void
{
    clearConsole();
    std::cout << "Available files: " << std::endl;
    showFilesTxt();
    std::cout << "Enter the name of the file: ";
    std::string fileName{};
    std::cin.ignore();
    std::getline(std::cin, fileName);
    fileName += ".txt";

    std::ifstream inFile(fileName);
    if (!inFile.is_open())
    {
        std::cout << "File not found." << std::endl;
        return;
    }

    int sum = 0;
    inFile >> sum;
    inFile.close();

    std::cout << "Total pages read from " << fileName << ": " << sum << std::endl;
}

auto Program::handleShowAvailableFiles()-> void
{
    clearConsole();
    std::cout << "Available files: " << std::endl;
    showFilesTxt();
}

auto Program::handleShowContentOfFile()-> void
{
    clearConsole();
    std::cout << "Available files: " << std::endl;
    showFilesTxt();

    std::string fileName{};
    std::cout << "Enter the name of the file you want to see the contents: ";
    std::cin.ignore();
    std::getline(std::cin, fileName);
    fileName += ".txt";

    std::ifstream inFile(fileName);
    if (not inFile.is_open())
    {
        std::cout << "File not found." << std::endl;
        return;
    }

    std::string content{};
    std::getline(inFile, content);
    inFile.close();

    std::cout << "Content of " << fileName << ": " << content << std::endl;
}

auto Program::handleDeleteFile() -> void
{
    clearConsole();
    std::cout << "Available files: " << std::endl;
    showFilesTxt();

    std::string fileName{};
    std::cout << "Enter the name of the file you want to delete: ";
    std::cin.ignore();
    std::getline(std::cin, fileName);
    fileName += ".txt";

    if (std::filesystem::remove(fileName))
    {
        std::cout << "File " << fileName << " deleted." << std::endl;
    }
    else
    {
        std::cout << "File not found." << std::endl;
    }
}

auto Program::handleCalculatePages() -> void
{
    clearConsole();
    int startingPage{ 0 };
    int endPage{ 0 };
    std::cout << "Enter the starting page: ";
    std::cin >> startingPage;
    std::cout << "Enter the last page you read today: ";
    std::cin >> endPage;

    int totalPagesRead = endPage - startingPage;
    std::cout << "You have read " << totalPagesRead << " pages today." << std::endl;
}

auto Program::run() -> void
{
    ProgramMode programMode;
    do
    {
        showMenu();
        std::cout << "Choose: ";
        std::cin >> programMode;

        switch (programMode)
        {
        case ProgramMode::p_numberOfPagesPerDay:
            handleNumberOfPagesPerDay();
            break;
        case ProgramMode::p_sumOfReadPagesInBook:
            handleSumOfReadPagesInBook();
            break;
        case ProgramMode::p_showAvailableFiles:
            handleShowAvailableFiles();
            break;
        case ProgramMode::p_showContentOfFile:
            handleShowContentOfFile();
            break;
        case ProgramMode::p_deleteFile:
            handleDeleteFile();
            break;
        case ProgramMode::p_calculatePages:
            handleCalculatePages();
            break;
        case ProgramMode::p_exit:
            std::cout << "See you tomorrow\n";
            break;
        default:
            clearConsole();
            std::cout << "Invalid choice\n";
            break;
        }
    } while (programMode != ProgramMode::p_exit);
}
