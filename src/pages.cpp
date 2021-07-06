#include "pages.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

std::istream &operator>>(std::istream &in, Pages &enter)
{
    int int_entry;
    enter = (in >> int_entry) ? static_cast<Pages>(int_entry) : Pages::p_exit;
    return in;
}

std::string HowManyPages::enterTitle() const
{
    std::string nameFileToSave;
    std::cout << "Enter book's title: ";
    std::cin >> nameFileToSave;
    return nameFileToSave;
}

void HowManyPages::SaveToFile(HowManyPages &savedate, std::string &tit)
{

    std::ofstream save(tit.c_str(), std::ios::app);
    if (save.good())
    {
        save << "Date: " << savedate.DateOfReading << ", number of pages: " << savedate.NumberOfPagesRead << '\n';
    }
    std::cout << "Data has been saved !\n";
    save.close();
    // return savedate;
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

void HowManyPages::sum()
{
    HowManyPages p;
    std::string nameFileToSave;
    std::cout << "Enter book's title: ";
    std::cin >> nameFileToSave;
    // nameFileToSave += ".txt";

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

void HowManyPages::menu()
{
    Pages enter;
    do
    {
        std::cout << "[1] Enter day and number of pages next enter book's title (automatic save)\n";
        std::cout << "[2] Add up the number of pages from a given book \n";
        std::cout << "[3] Count how many pages you have read \n";
        std::cout << "[4] Exit \n";
        std::cout << "Choose: ";
        std::cin >> enter;
        HowManyPages p;
        switch (enter)
        {
        case Pages::p_PagesDay:
        {
            system("clear");
            p.enterdata();
            // enterTitle();
            break;
        }
        case Pages::p_Sum:
        {
            system("clear");
            p.sum();
            break;
        }
        case Pages::p_Calculate:
        {
            system("clear");
            std::cout << calc() << " pages\n";
            break;
        }
        case Pages::p_exit:
        {
            std::cout << "See you tomorrow \n";
            break;
        }
        default:
        {
            system("clear");
            std::cout << "nope \n";
            break;
        }
        }
    } while (enter != Pages::p_exit);
}
