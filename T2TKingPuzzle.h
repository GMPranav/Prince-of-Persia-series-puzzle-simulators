#pragma once

#include <string>
#include <vector>

#include "PuzzleCommon.h"

struct T2TKingPuzzle {
    struct State {
        int translationalPosition;
        int rotationalPosition;
        bool won;
    };

    static const char* name()
    {
        return "T2T King Statue";
    }

    static std::vector<std::string> moves()
    {
        return { "fw", "bw", "cw", "aw" };
    }

    static State initial()
    {
        return { 0, 0, false };
    }

    static const std::vector<std::string>& possibleMoves(int rotationalPosition, int translationalPosition)
    {
        static const std::vector<std::string> table[4][6] = {
            { { "fw", "aw" }, { "bw", "cw" }, { "fw", "aw" }, { "bw", "cw" }, { "fw", "cw" }, { "bw", "aw" } },
            { { "fw", "cw" }, { "bw", "aw" }, { "fw", "cw" }, { "bw", "aw" }, { "fw" }, { "bw", "cw" } },
            { { "fw" }, { "fw", "cw", "aw" }, { "fw", "bw" }, { "bw", "cw" }, { "fw", "aw" }, { "bw", "aw" } },
            { { "fw" }, { "cw", "aw" }, { "fw" }, { "fw", "aw" }, { "fw", "bw", "cw", "aw" }, { "bw", "cw" } }
        };
        return table[rotationalPosition][translationalPosition];
    }

    // Returns false, leaving the state untouched, when the move is not possible.
    static bool apply(State& state, const std::string& move)
    {
        if (state.won || !contains(possibleMoves(state.rotationalPosition, state.translationalPosition), move)) {
            return false;
        }

        if (move == "fw") {
            state.translationalPosition++;
            if (state.translationalPosition == 5 && state.rotationalPosition == 0) {
                state.won = true;
            }
        } else if (move == "bw") {
            state.translationalPosition--;
        } else if (move == "cw") {
            state.rotationalPosition = (state.rotationalPosition + 3) % 4;
        } else if (move == "aw") {
            state.rotationalPosition = (state.rotationalPosition + 1) % 4;
        }
        return true;
    }

    static bool isSolved(const State& state)
    {
        return state.won;
    }

    static unsigned long long encode(const State& state)
    {
        return (state.translationalPosition * 4ULL + state.rotationalPosition) * 2 + (state.won ? 1 : 0);
    }
};
