#include <iostream>
#include <string>
#include <vector>

#include "PuzzleCommon.h"
#include "T2TKingPuzzle.h"

using namespace std;

void printRotationalPosition(int rotationalPosition)
{
    switch (rotationalPosition) {
    case 0:
        cout << "Front";
        break;
    case 1:
        cout << "It's left";
        break;
    case 2:
        cout << "Back";
        break;
    case 3:
        cout << "It's right";
        break;
    default:
        break;
    }
}

int main()
{
    vector<string> moves;
    T2TKingPuzzle::State state = T2TKingPuzzle::initial();
    string choice;

    do {
        clearScreen();
        cout << "T2T King Statue Puzzle Simulator:" << endl
             << endl;
        cout << "Translational position: " << state.translationalPosition << endl;
        cout << "Rotational position: ";
        printRotationalPosition(state.rotationalPosition);
        cout << endl
             << endl;
        cout << "Legend (not case sensitive):" << endl
             << "CW = Clockwise" << endl
             << "AW = Anticlockwise" << endl
             << "FW = Forward" << endl
             << "BW = Backward" << endl
             << "EX = Exit" << endl
             << endl;

        cout << "Input your choice: ";
        choice = readChoice();

        if (T2TKingPuzzle::apply(state, choice)) {
            moves.push_back(choice);
            if (T2TKingPuzzle::isSolved(state)) {
                cout << endl
                     << endl
                     << "You beat the puzzle !" << endl;
                cout << "Nice moves! ";
                printMoves(moves);
                waitForKey();
                break;
            }
        }
    } while (choice != "ex");

    return 0;
}
