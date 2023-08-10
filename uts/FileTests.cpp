#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <filesystem>
#include "File.hpp"

class FileTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        tempFilePath = std::filesystem::temp_directory_path() / "test_file.txt";
        std::ofstream tempFile(tempFilePath.string());
        tempFile << "Test content\n";
        tempFile.close();
    }

    void TearDown() override
    {
        std::filesystem::remove(tempFilePath);
    }

    std::filesystem::path tempFilePath;
};

TEST_F(FileTest, ContentOfTheFileMatch)
{
    File file(tempFilePath.string());
    EXPECT_TRUE(file.is_open());

    std::string line{};
    file.readLine(line);
    EXPECT_EQ(line, "Test content");
}

TEST_F(FileTest, ContentMismatch)
{
    File file(tempFilePath.string());
    EXPECT_TRUE(file.is_open());

    std::string line;
    file.readLine(line);
    EXPECT_FALSE(line == "Incorrect content");
}

