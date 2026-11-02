#pragma once

#include <string>
#include <vector>

struct WaterPillarPuzzle {
    struct State {
        int lower;
        int middle;
        int upper;
        int middleJoint;
        int upperJoint;
    };

    static const char* name()
    {
        return "TFS Water Pillar";
    }

    static std::vector<std::string> moves()
    {
        return { "fa", "fc", "na", "nc" };
    }

    static State initial()
    {
        return { 1, 4, 2, 1, 4 };
    }

    // Pieces are numbered 1-4; direction is +1 for clockwise, -1 for anticlockwise.
    static int turn(int piece, int direction)
    {
        return (piece - 1 + direction + 4) % 4 + 1;
    }

    static void normalMove(State& state, int direction)
    {
        state.lower = turn(state.lower, direction);
        state.middle = turn(state.middle, direction);
        state.upper = turn(state.upper, direction);
        state.middleJoint = turn(state.middleJoint, direction);
        state.upperJoint = turn(state.upperJoint, direction);
    }

    // A frozen move leaves alone the pieces that would otherwise pass the blocked position.
    static void freezeMove(State& state, int direction, int blocked)
    {
        if (state.upper != blocked && state.upperJoint != blocked) {
            state.upper = turn(state.upper, direction);
            state.upperJoint = turn(state.upperJoint, direction);
        }
        if (state.middle != blocked && state.middleJoint != blocked) {
            state.middle = turn(state.middle, direction);
            state.middleJoint = turn(state.middleJoint, direction);
        }
        if (state.lower != blocked) {
            state.lower = turn(state.lower, direction);
        }
    }

    // Returns false when the move is not one of the four lever moves.
    static bool apply(State& state, const std::string& move)
    {
        if (move == "nc") {
            normalMove(state, 1);
        } else if (move == "na") {
            normalMove(state, -1);
        } else if (move == "fc") {
            freezeMove(state, 1, 4);
        } else if (move == "fa") {
            freezeMove(state, -1, 1);
        } else {
            return false;
        }
        return true;
    }

    static bool isSolved(const State& state)
    {
        return state.lower == 4 && state.middle == 4 && state.upper == 4;
    }

    static unsigned long long encode(const State& state)
    {
        unsigned long long key = 0;
        for (int piece : { state.lower, state.middle, state.upper, state.middleJoint, state.upperJoint }) {
            key = key * 4 + (piece - 1);
        }
        return key;
    }
};
