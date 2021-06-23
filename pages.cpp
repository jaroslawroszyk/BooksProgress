#include "pages.h"
#include <fstream>

std::istream &operator>>(std::istream &in, Pages &enter)
{
    int int_entry;
    enter = (in >> int_entry) ? static_cast<Pages>(int_entry) : Pages::p_exit;
    return in;
}

HowManyPages SaveToFile(HowManyPages savedate)
{
    HowManyPages t; // wyjeb
    std::ofstream save;
    save.open("dane.txt", std::ios::app);
    if (save.good())
    {
        save << "Date: " << savedate.date << ", number of pages: " << savedate.pages << '\n';
        std::cout << "Wrote!\n";
    }

    save.close();
    return t; //zwroc savedata
}

void sum(HowManyPages k)
{
    // HowManyPages xd;
    int suma;
    std::string line;
    std::cout << "sum all pages \n";
    std::ifstream outFile;
    outFile.open("dane.txt", std::ios::app | std::ios::in);
    if (outFile.is_open())
    {
        // while (getline(outFile, line))
        while(outFile >> line)
        {
            suma += k.pages;
            
        }
        std::cout << suma << "\n";
        outFile.close();
    }
    else
    {
        std::cout << "Unable to open file! \n";
    }

}

HowManyPages enterdata()
{
    HowManyPages p;
    std::cout << "enter the day: ";
    std::cin >> p.date;
    std::cout << "how many pages: ";
    std::cin >> p.pages;
    // show(p);
    sum(p);
    SaveToFile(p);
    return p;
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
            // sum();
            break;
        }
        case Pages::p_exit:
        {
            std::cout << "See you tomorrow \n";
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