#include "IBookStatistic.hpp"
#include "BookStatistic.hpp"
#include "IProgram.hpp"
#include "Program.hpp"
#include <memory>

int main()
{
    std::shared_ptr<IBookStatistic> bookStats = std::make_shared<BookStatistic>();
    std::shared_ptr<IProgram> program = std::make_shared<Program>(bookStats);
    program->run();
    return 0;
}
