#include <iostream>
#include <string>

#include "PuzzleCommon.h"
#include "WaterPillarPuzzle.h"

using namespace std;

int main()
{
    WaterPillarPuzzle::State pillar = WaterPillarPuzzle::initial();
    string choice;

    do {
        clearScreen();
        cout << "TFS Water Pillar Puzzle Simulator:" << endl
             << endl;
        cout << "Current positions are:" << endl;
        cout << "Lower piece: " << pillar.lower << endl;
        cout << "Middle piece: " << pillar.middle << endl;
        cout << "Upper piece: " << pillar.upper << endl
             << endl;
        cout << "Move list: FA, FC, NA, NC. Type re to reset, ex to exit" << endl;

        cout << "Input your choice (not case sensitive): ";
        choice = readChoice();

        if (choice == "re") {
            pillar = WaterPillarPuzzle::initial();
        } else {
            WaterPillarPuzzle::apply(pillar, choice);
        }
    } while (choice != "ex");

    return 0;
}
