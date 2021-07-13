#include "BookStatistic.h"
#include "ProgramMode.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <limits>
#include <iostream>


std::istream &operator>>(std::istream &in, ProgramMode &enter)
{
    int int_entry;
    enter = (in >> int_entry) ? static_cast<ProgramMode>(int_entry) : ProgramMode::p_exit;
    return in;
}

std::string BookStatistic::enterTitle() const
{
    std::string nameFileToSave;
    std::cout << "Enter book's title(without extension): ";
    std::cin >> nameFileToSave;
    // std::cin.ignore(); the version with the entire title of the book
    // std::getline(std::cin,nameFileToSave);
    nameFileToSave += ".txt";
    return nameFileToSave;
}

void BookStatistic::enterdata()
{
    std::string en = enterTitle();
    std::cout << "enter the day: ";
    std::cin >> DateOfReading;
    std::cout << "how many pages: ";
    std::cin >> NumberOfPagesRead;
    SaveToFile(en);
}

void BookStatistic::SaveToFile(const std::string &BookTitle) const
{
    std::ofstream save(BookTitle.c_str(), std::ios::app);
    if (save.good())
    {
        save << "Date: " << DateOfReading << ", number of pages: " << NumberOfPagesRead << '\n';
    }
    std::cout << "Data has been saved !\n";
    save.close();
}

void BookStatistic::sum() const
{
    BookStatistic p;
    std::string nameFileToSave;
    std::cout << "Enter book's title(without extension): ";
    std::cin >> nameFileToSave;
    nameFileToSave += ".txt";

    std::string line;
    std::ifstream outFile;
    outFile.open(nameFileToSave.c_str(), std::ios::app | std::ios::in);
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

