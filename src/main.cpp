#include "IFile.hpp"
#include "IBookStatistic.hpp"
#include "BookStatistic.hpp"
#include "IProgram.hpp"
#include "Program.hpp"
#include "File.hpp"
#include <memory>

int main()
{
    std::shared_ptr<IFile> file = std::make_shared<File>("nazwa_pliku.txt");
    std::shared_ptr<IBookStatistic> bookStats = std::make_shared<BookStatistic>();
    std::shared_ptr<IProgram> program = std::make_shared<Program>(bookStats, file);

    program->run();
    return 0;
}
