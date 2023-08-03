#include "BookStatistic.hpp"
#include <fstream>
#include <string>
#include <cstdlib>
#include <limits>
#include <iostream>

auto BookStatistic::enterTitle() const -> std::string
{
    std::string nameFileToSave{};
    std::cout << "Enter book's title (without extension): ";
    std::cin >> nameFileToSave;
    nameFileToSave += ".txt";
    return nameFileToSave;
}

auto BookStatistic::enterData() -> void
{
    std::string title = enterTitle();
    std::cout << "Enter the day: ";
    std::cin >> dateOfReading;
    std::cout << "How many pages: ";
    std::cin >> numberOfPagesRead;
    saveToFile(title);
}

auto BookStatistic::saveToFile(const std::string& BookTitle) const -> void
{
    std::ofstream save(BookTitle.c_str(), std::ios::app);
    if (save.good())
    {
        save << "Date: " << dateOfReading << ", number of pages: " << numberOfPagesRead << '\n';
        std::cout << "Data has been saved!\n";
    }
    else
    {
        std::cout << "Unable to open file!\n";
    }
    save.close();
}

auto BookStatistic::calculateTotalPagesRead() const -> void
{
    BookStatistic bookStatistic;
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
                bookStatistic.numberOfPagesRead = std::stoi(token);
                bookStatistic.sumPages += bookStatistic.numberOfPagesRead;
            }
        }
        outFile.close();
        std::cout << "From the book " << nameFileToSave << " the total number of pages read is: " << p.sumPages << std::endl;
    }
    else
    {
        std::cout << "Unable to open file!\n";
    }
}
