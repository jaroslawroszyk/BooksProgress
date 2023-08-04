#pragma once
#include <istream>
#include <string>

class IFile
{
public:
    virtual ~IFile() {}
    virtual bool is_open() = 0;
    virtual void close() = 0;
    virtual std::istream& getline(std::string& line) = 0;
    virtual std::istream& readLine(std::string& line) = 0;
};
