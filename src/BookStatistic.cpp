#include "BookStatistic.hpp"
#include <iostream>
#include <fstream>
#include <string>

auto BookStatistic::enterTitle() const -> std::string
{
    std::string nameFileToSave{};
    std::cout << "Enter book's title (without extension): ";
    std::cin >> nameFileToSave;
    nameFileToSave += ".txt";
    return nameFileToSave;
}

void BookStatistic::enterData()
{
    std::string title = enterTitle();
    std::cout << "Enter the day: ";
    std::cin >> dateOfReading;
    std::cout << "How many pages: ";
    std::cin >> numberOfPagesRead;
    saveToFile(title);
}

void BookStatistic::saveToFile(const std::string& BookTitle) const
{
    std::ofstream file(BookTitle.c_str(), std::ios::app);
    if (file.good())
    {
        file << "Date: " << dateOfReading << ", number of pages: " << numberOfPagesRead << '\n';
        std::cout << "Data has been saved!\n";
    }
    else
    {
        std::cout << "Unable to open file!\n";
    }
    file.close();
}

BookStatistic BookStatistic::calculateTotalPagesRead() const
{
    BookStatistic bookStat{};
    std::string nameFileToSave = enterTitle();

    std::string line{};
    std::ifstream outFile(nameFileToSave);

    if (outFile.is_open())
    {
        while (getline(outFile, line))
        {
            size_t pos = line.find(":");
            if (pos != std::string::npos)
            {
                std::string token = line.substr(pos + 1);
                bookStat.numberOfPagesRead = std::stoi(token);
                bookStat.sumPages += bookStat.numberOfPagesRead;
            }
        }
        outFile.close();
    }
    else
    {
        std::cout << "Unable to open file!\n";
    }
    return bookStat;
}

int BookStatistic::getSumPages() const
{
    return sumPages;
}
