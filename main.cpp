#include <util/arguments.h>
#include <strategy/strategyFactory.h>
#include <solver/solver.h>

int main(int argc, char **argv) {
    sise::arguments arguments(argc, argv);

    if (arguments.size() != 6)
        sise::Throw("invalid number of arguments: " + std::to_string(arguments.size()));

    auto strategy = sise::strategyFactory::get(arguments[1], arguments[2]);

    std::shared_ptr<sise::board> board(std::make_shared<sise::board>(arguments[3]));

    sise::solver solver(board, strategy);

    solver.solve();

    solver.saveSolution(arguments[4]);

    solver.saveStats(arguments[5]);

    return 0;
}
