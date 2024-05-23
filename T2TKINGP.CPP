#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void clearScreenPart()
{
    cout << "\033[H\033[J";
}

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
    const vector<string> possibleMoves[4][6] = {
        { { "fw", "aw" }, { "bw", "cw" }, { "fw", "aw" }, { "bw", "cw" }, { "fw", "cw" }, {} },
        { { "fw", "cw" }, { "fw", "bw", "aw" }, { "fw", "cw" }, { "bw", "aw" }, { "fw" }, { "bw", "cw" } },
        { {}, { "fw", "cw", "aw" }, { "fw", "bw" }, { "bw", "cw" }, { "fw", "aw" }, { "bw", "aw" } },
        { {}, { "cw", "aw" }, { "fw" }, { "fw", "aw" }, { "fw", "bw", "cw", "aw" }, { "bw", "cw" } }
    };

    int translationalPosition = 0;
    int rotationalPosition = 0;
    string choice;

    do {
        clearScreenPart();
        cout << "T2T King Statue Puzzle Simulator:" << endl
             << endl;
        cout << "Translational position: " << translationalPosition << endl;
        cout << "Rotational position: ";
        printRotationalPosition(rotationalPosition);
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
        cin >> choice;
        transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

        vector<string> possibleChoices = possibleMoves[rotationalPosition][translationalPosition];

        if (find(possibleChoices.begin(), possibleChoices.end(), choice) != possibleChoices.end()) {
            moves.push_back(choice);
            if (choice == "fw") {
                translationalPosition++;
                if (translationalPosition == 5) {
                    cout << endl
                         << endl
                         << "You beat the puzzle !" << endl;
                    cout << "Nice moves! ";
                    for (string move : moves) {
                        cout << move << " ";
                    }
                    cin.get();
                    cin.get();
                    break;
                }
            } else if (choice == "bw") {
                translationalPosition--;
            } else if (choice == "cw") {
                rotationalPosition = (rotationalPosition + 3) % 4;
            } else if (choice == "aw") {
                rotationalPosition = (rotationalPosition + 1) % 4;
            }
        }
    } while (choice != "ex");

    return 0;
}
