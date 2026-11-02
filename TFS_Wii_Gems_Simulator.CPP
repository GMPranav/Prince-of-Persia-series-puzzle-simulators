#include <iostream>
#include <string>
#include <vector>

#include "PuzzleCommon.h"
#include "WiiGemsPuzzle.h"

using namespace std;

int main()
{
    vector<string> moves;
    WiiGemsPuzzle::State state = WiiGemsPuzzle::initial();
    string choice;

    do {
        clearScreen();
        cout << "TFS Wii Gems Puzzle Simulator:" << endl
             << endl;
        cout << "Move list: LA, LC, RA, RC. Type re to reset, ex to exit" << endl;
        cout << "Current position: " << state.rings.left[0] << " " << state.rings.right[0] << " "
             << state.rings.left[4] << " " << state.rings.right[4] << endl;

        cout << "Input your choice (not case sensitive): ";
        choice = readChoice();

        if (WiiGemsPuzzle::apply(state, choice)) {
            moves.push_back(choice);
        } else if (choice == "re") {
            state.rings = WiiGemsPuzzle::initialRings();
            moves.clear();
        }

        for (int gem = 1; gem <= WiiGemsPuzzle::gemCount; gem++) {
            if (WiiGemsPuzzle::isGemSolved(state.rings, gem)) {
                cout << endl
                     << WiiGemsPuzzle::gemName(gem) << " solved!" << endl;
                waitForKey();
            }
        }

        if (WiiGemsPuzzle::isSolved(state)) {
            cout << endl
                 << "Congrats! You have solved the puzzle!" << endl;
            cout << "Move list: ";
            printMoves(moves);
            waitForKey();
            break;
        }
    } while (choice != "ex");

    return 0;
}
