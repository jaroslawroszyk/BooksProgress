#include "pages.h"
#include <fstream>
#include <string>

std::istream &operator>>(std::istream &in, Pages &enter)
{
    int int_entry;
    enter = (in >> int_entry) ? static_cast<Pages>(int_entry) : Pages::p_exit;
    return in;
}

HowManyPages SaveToFile(HowManyPages savedate)
{
    std::ofstream save;
    save.open("dane.txt", std::ios::app);
    if (save.good())
    {
        save << "Date: " << savedate.date << ", number of pages: " << savedate.pages << '\n';
        std::cout << "Data has been saved !\n";
    }
    save.close();
    return savedate;
}

// int extract_pages(const std::string &line)
// {
//     std::string number;
//     for (auto iter{crbegin(line)}; iter != crend(line); ++iter)
//     {
//         if (!isdigit(*iter))
//             break;
//         number += *iter;
//     }
//     return stoi(std::string{rbegin(number), rend(number)});
// }

void sum()
{
    //first version
    HowManyPages p;
    std::string line;
    std::cout << "sum all pages \n";
    std::ifstream outFile;
    outFile.open("dane.txt", std::ios::app);
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
    std::cout << "Sum of pages : " << p.suma << std::endl;

    //secound  version:
    //     auto file = std::ifstream("dane.txt");
    // int sum = 0;
    // for(;;) {
    //     file.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    //     file.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    //     if(file.eof() || file.bad()) {
    //         break;
    //     }
    //     int i;
    //     file >> i;
    //     sum += i;
    // }
    // std::cout << "sum = " << sum << '\n';
}

void enterdata()
{
    HowManyPages p;
    std::cout << "enter the day: ";
    std::cin >> p.date;
    std::cout << "how many pages: ";
    std::cin >> p.pages;
    SaveToFile(p);
}

void menu()
{
    Pages enter;
    do
    {
        std::cout << "[1] Enter day and number of pages (automatic save)\n";
        std::cout << "[2] Sum all day \n";
        std::cout << "[3] Exit \n";
        std::cout << "Choose: ";
        std::cin >> enter;
        switch (enter)
        {
        case Pages::p_PagesDay:
        {
            system("clear");
            enterdata();
            break;
        }
        case Pages::p_Sum:
        {
            system("clear");
            sum();
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