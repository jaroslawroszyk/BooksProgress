#include "File.hpp"
#include <iostream>
#include <fstream>
#include <string>

File::File(const std::string& filename)
{
    fileStream.open(filename);
}

File::~File()
{
    if (fileStream.is_open())
    {
        fileStream.close();
    }
}

auto File::is_open() -> bool
{
    return fileStream.is_open();
}

auto File::close() -> void
{
    if (fileStream.is_open())
    {
        fileStream.close();
    }
}

std::istream& File::getline(std::string& line)
{
    return std::getline(fileStream, line);
}

std::istream& File::readLine(std::string& line)
{
    return std::getline(fileStream, line);
}
