#include "pages.h"
#include <fstream>
#include <string>
#include <iostream>
void SaveToFile(HowManyPages savedate,std::string tit);

std::istream &operator>>(std::istream &in, Pages &enter)
{
    int int_entry;
    enter = (in >> int_entry) ? static_cast<Pages>(int_entry) : Pages::p_exit;
    return in;
}

std::string enterTitle()
{
    std::string nameFileToSave;
    std::cout << "Enter book's title: ";
    std::cin >> nameFileToSave;
    return nameFileToSave;
}

void enterdata()
{
    HowManyPages p;
    std::string en = enterTitle();
    std::cout << "enter the day: ";
    std::cin >> p.date;
    std::cout << "how many pages: ";
    std::cin >> p.pages;
    SaveToFile(p,en);
    
}

void SaveToFile(HowManyPages savedate,std::string tit)
{
    //enter book's title
    // std::string nameFileToSave;
    // std::cout << "Enter book's title: ";
    // std::cin >> nameFileToSave;
    // nameFileToSave += ".txt";
    // std::string n;
    //saving to a given data file

    // std::string sth = enterTitle();
    std::ofstream save(tit.c_str(), std::ios::app);
    if (save.good())
    {
        save << "Date: " << savedate.date << ", number of pages: " << savedate.pages << '\n';
    }
    std::cout << "Data has been saved !\n";
    save.close();
    // return savedate;
}

void sum()
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
            p.pages = std::stoi(token2);
            p.suma += p.pages;
        }
        outFile.close();
    }
    else
    {
        std::cout << "Unable to open file! \n";
    }
    std::cout << "From the book " << nameFileToSave << " the total number of pages read is: " << p.suma << std::endl; 
    // std::cout << "Sum of pages: " << p.suma << std::endl;
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



void menu()
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
        switch (enter)
        {
        case Pages::p_PagesDay:
        {
            system("clear");
            enterdata();
            // enterTitle();
            break;
        }
        case Pages::p_Sum:
        {
            system("clear");
            sum();
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

// void EnterData()
// {
//     HowManyPages test;

//     std::cout << "enter the day: ";
//     std::cin >> test.date;
//     std::cout << "how many pages: ";
//     std::cin >> test.pages;
// }

// void show(HowManyPages show)
// {
//     std::cout<< show.date << " " << show.pages << "\n";
// }