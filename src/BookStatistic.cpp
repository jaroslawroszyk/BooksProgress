#include "BookStatistic.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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

BookStatistic BookStatistic::calculateTotalPagesRead(const std::string& nameFileToSave) const
{
    BookStatistic bookStat{};

    std::string line{};
    std::ifstream outFile(nameFileToSave);

    if (outFile.is_open())
    {
        while (std::getline(outFile, line))
        {
            size_t pos = line.find("number of pages:");
            if (pos != std::string::npos)
            {
                std::string token = line.substr(pos + 16);
                std::istringstream iss(token);
                int numberOfPages = 0;
                iss >> numberOfPages;
                if (iss.fail())
                {
                    std::cout << "Failed to parse number of pages from token: " << token << std::endl;
                }
                else
                {
                    bookStat.numberOfPagesRead = numberOfPages;
                    bookStat.sumPages += bookStat.numberOfPagesRead;
                }
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
