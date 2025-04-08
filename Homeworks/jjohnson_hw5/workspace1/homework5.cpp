#include "Simulation.hpp"

#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));
    Simulation s(100, 10);
    s.run();

    // terminate
    return 0;
}
