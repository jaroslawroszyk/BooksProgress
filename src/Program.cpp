#include "BookStatistic.hpp"
#include "ProgramMode.hpp"
#include "Program.hpp"
#include <cstdlib>
#include <iostream>
#include <filesystem>
#include <fstream>

auto Program::calculatePages() -> int
{
    int startingPage = 0;
    int endPage = 0;
    int calculate = 0;
    std::cout << "Enter the starting page: ";
    std::cin >> startingPage;
    std::cout << "Enter the last page you read today: ";
    std::cin >> endPage;
    calculate = endPage - startingPage;
    std::cout << "you have read: ";
    return calculate;
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

auto Program::deleteFile() -> void
{
    std::string nameFile{};
    std::cout << "Enter the name of the file you want to delete(without extension .txt): " << std::endl;

    std::cin >> nameFile;
    nameFile += ".txt";
    try
    {
        if (std::filesystem::remove(nameFile))
        {
            std::cout << "File " << nameFile << " deleted.\n";
        }
        else
        {
            std::cout << "file " << nameFile << " not found.\n";
        }
    }
    catch (const std::filesystem::filesystem_error& err)
    {
        std::cout << " filesystem error: " << err.what() << "\n";
    }
}

auto Program::showContent() -> void
{
    std::string nameFile{};
    std::cout << "Enter the name of the file you want to see the contents(without extension): ";
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
        {
            clearConsole();
            std::cout << "Available files: " << std::endl;
            showFilesTxt();
            std::cout << std::endl << std::endl;
            bookStats.enterData();
            break;
        }
        case ProgramMode::p_sumOfReadPagesInBook:
        {
            clearConsole();
            std::cout << "Available files: " << std::endl;
            showFilesTxt();
            std::cout << std::endl;
            bookStats.calculateTotalPagesRead();
            break;
        }
        case ProgramMode::p_showAvailableFiles:
        {
            clearConsole();
            std::cout << "Available files: " << std::endl;
            showFilesTxt();
            std::cout << std::endl;
            break;
        }
        case ProgramMode::p_showContentOfFile:
        {
            clearConsole();
            std::cout << "Available files: " << std::endl;
            showFilesTxt();
            std::cout << std::endl;
            showContent();
            break;
        }
        case ProgramMode::p_deleteFile:
        {
            clearConsole();
            std::cout << "Available files: " << std::endl;
            showFilesTxt();
            std::cout << std::endl;
            deleteFile();
            break;
        }
        case ProgramMode::p_calculatePages:
        {
            clearConsole();
            std::cout << calculatePages() << " pages\n";
            break;
        }
        case ProgramMode::p_exit:
        {
            std::cout << "See you tomorrow \n";
            break;
        }
        default:
        {
            clearConsole();
            std::cout << "Invalid choice \n";
            break;
        }
        }
    } while (programMode != ProgramMode::p_exit);
}
