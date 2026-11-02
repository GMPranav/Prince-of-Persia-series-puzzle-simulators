#include <cstdlib>
#include <iostream>
#include <string>

#include "Bruteforcer.h"
#include "T2TKingPuzzle.h"
#include "WaterPillarPuzzle.h"
#include "WiiGemsPuzzle.h"

using namespace std;

int main(int argc, char* argv[])
{
    string puzzle = argc > 1 ? argv[1] : "all";
    int maxMoves = argc > 2 ? atoi(argv[2]) : 15;
    size_t maxPrint = argc > 3 ? atoi(argv[3]) : 10;

    bool known = puzzle == "all" || puzzle == "t2t" || puzzle == "pillar" || puzzle == "gems";
    if (!known) {
        cout << "Usage: Bruteforcer [t2t|pillar|gems|all] [max moves = 15] [solutions to print = 10]" << endl;
        return 1;
    }

    if (puzzle == "all" || puzzle == "t2t") {
        bruteforce<T2TKingPuzzle>(maxMoves, maxPrint);
    }
    if (puzzle == "all" || puzzle == "pillar") {
        bruteforce<WaterPillarPuzzle>(maxMoves, maxPrint);
    }
    if (puzzle == "all" || puzzle == "gems") {
        bruteforce<WiiGemsPuzzle>(maxMoves, maxPrint);
    }

    return 0;
}
