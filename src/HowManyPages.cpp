#include "HowManyPages.h"
#include "ProgramMode.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <limits>
#include <iostream>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
std::istream &operator>>(std::istream &in, ProgramMode &enter)
{
    int int_entry;
    enter = (in >> int_entry) ? static_cast<ProgramMode>(int_entry) : ProgramMode::p_exit;
    return in;
}

std::string HowManyPages::enterTitle() const
{
    std::string nameFileToSave;
    std::cout << "Enter book's title: ";
    std::cin >> nameFileToSave;
    nameFileToSave += ".txt";
    return nameFileToSave;
}

void HowManyPages::SaveToFile(const HowManyPages &savedate, std::string &BookTitle)
{
    std::ofstream save(BookTitle.c_str(), std::ios::app);

    if (save.good())
    {
        save << "Date: " << savedate.DateOfReading << ", number of pages: " << savedate.NumberOfPagesRead << '\n';
    }
    std::cout << "Data has been saved !\n";
    save.close();
}

void HowManyPages::enterdata()
{
    HowManyPages p;
    std::string en = enterTitle();
    std::cout << "enter the day: ";
    std::cin >> p.DateOfReading;
    std::cout << "how many pages: ";
    std::cin >> p.NumberOfPagesRead;
    SaveToFile(p, en);
}

void HowManyPages::sum() const
{
    HowManyPages p;
    std::string nameFileToSave;
    std::cout << "Enter book's title: ";
    std::cin >> nameFileToSave;
    nameFileToSave += ".txt";

    std::string line;
    std::ifstream outFile;
    outFile.open(nameFileToSave.c_str(), std::ios::app);
    if (outFile.is_open())
    {
        while (getline(outFile, line))
        {
            std::string token1 = line.substr(line.find(",") + 1, line.length() - 1);
            std::string token2 = token1.substr(token1.find(":") + 1, token1.length() - 1);
            p.NumberOfPagesRead = std::stoi(token2);
            p.SumPages += p.NumberOfPagesRead;
        }
        outFile.close();
    }
    else
    {
        std::cout << "Unable to open file! \n";
    }
    std::cout << "From the book " << nameFileToSave << " the total number of pages read is: " << p.SumPages << std::endl;
}

int calc()
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

void showFilesTxt()
{
    DIR *d;
    char *p1, *p2;
    int ret;
    struct dirent *dir;
    d = opendir(".");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            p1 = strtok(dir->d_name, ".");
            p2 = strtok(NULL, ".");
            if (p2 != NULL)
            {
                ret = strcmp(p2, "txt");
                if (ret == 0)
                {
                    std::cout << p1 << "\n";
                }
            }
        }
        closedir(d);
    }
}

void menu()
{
    ProgramMode enter;
    do
    {
        std::cout << "[1] Enter day and number of pages next enter book's title (automatic save)\n";
        std::cout << "[2] Add up the number of pages from a given book \n";
        std::cout << "[3] Show available files \n";
        std::cout << "[4] Count how many pages you have read \n";
        std::cout << "[5] Exit \n";
        std::cout << "Choose: ";
        std::cin >> enter;
        HowManyPages p;
        switch (enter)
        {
        case ProgramMode::p_PagesDay:
        {
            std::system("clear");
            std::cout << "Available files: " << std::endl;
            showFilesTxt();
            std::cout << std::endl
                      << std::endl;
            p.enterdata();
            // enterTitle();
            break;
        }
        case ProgramMode::p_Sum:
        {
            std::system("clear");
            std::cout << "Available files: " << std::endl;
            showFilesTxt();
            std::cout << std::endl;
            p.sum();
            break;
        }
        case ProgramMode::p_Show:
        {
            std::system("clear");
            std::cout << "Available files: " << std::endl;
            showFilesTxt();
            std::cout << std::endl;
            break;
        }
        case ProgramMode::p_Calculate:
        {
            std::system("clear");
            std::cout << calc() << " pages\n";
            break;
        }
        case ProgramMode::p_exit:
        {
            std::cout << "See you tomorrow \n";
            break;
        }
        default:
        {
            std::system("clear");
            std::cout << "nope \n";
            break;
        }
        }
    } while (enter != ProgramMode::p_exit);
}
