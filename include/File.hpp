#include "IFile.hpp"
#include <fstream>
#include <string>

class File : public IFile
{
private:
    std::ifstream fileStream;

public:
    File(const std::string&);
    ~File();

    auto is_open() -> bool override;
    auto close() -> void override;
    std::istream& getline(std::string&) override;
    std::istream& readLine(std::string&) override;

};
