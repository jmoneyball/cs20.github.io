#include "utils.hpp"

#include "Tyrannosaurus.hpp"
#include "Stegosaurus.hpp"
#include "Brachiosaurus.hpp"
#include "Chicken.hpp"

#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    const int NUM_DINOS = 4;
    Dinosaur* competitors[NUM_DINOS] {
        new Tyrannosaurus(), new Stegosaurus(),
        new Brachiosaurus(), new Chicken()
    };

    welcome(competitors);
    display(competitors, NUM_DINOS);
    conquer(competitors, NUM_DINOS);
    display(competitors, NUM_DINOS);
    victoryMessage(competitors, NUM_DINOS);

    for (int i = 0; i < NUM_DINOS; i++) {
        delete competitors[i];
    }

    return 0;
}
