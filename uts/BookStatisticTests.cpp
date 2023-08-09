#include <gtest/gtest.h>
#include "BookStatistic.hpp"
#include <fstream>
#include <string>

namespace
{
    auto fillContentInFile(const std::string& filename) -> std::ofstream
    {
        std::ofstream testFile(filename);
        if (testFile.is_open())
        {
            testFile << "Date: 2023-08-10, number of pages: 50\n";
            testFile << "Date: 2023-08-11, number of pages: 30\n";
            testFile.close();
        }
        return testFile;
    }
}

class BookStatisticTest : public ::testing::Test
{
protected:
    BookStatistic bookStat{};
    std::string fileName{ "test_data.txt" };


    void SetUp() override
    {
        fillContentInFile(fileName);

    }

    void TearDown() override
    {
        std::remove(fileName.c_str());
    }
};

TEST_F(BookStatisticTest, CalculateTotalPagesRead)
{
    bookStat.saveToFile(fileName);

    BookStatistic result = bookStat.calculateTotalPagesRead(fileName);

    EXPECT_EQ(result.getSumPages(), 80);

}
