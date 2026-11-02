#pragma once

#include <algorithm>
#include <array>
#include <string>
#include <vector>

#include "PuzzleCommon.h"

struct WiiGemsPuzzle {
    typedef std::array<int, 8> Ring;

    struct Rings {
        Ring left;
        Ring right;
    };

    struct State {
        Rings rings;
        unsigned solvedMask; // a gem stays solved once it has been solved, even across resets
    };

    enum { wildcard = 5, gemCount = 4 };

    static const char* name()
    {
        return "TFS Wii Gems";
    }

    static const std::string& gemName(int gem)
    {
        static const std::string names[gemCount] = { "Yellow", "Green", "Orange", "Purple" };
        return names[gem - 1];
    }

    static std::vector<std::string> moves()
    {
        return { "la", "lc", "ra", "rc" };
    }

    static Rings initialRings()
    {
        return { { { 1, 2, 3, 1, 5, 3, 4, 4 } }, { { 2, 1, 0, 4, 3, 1, 2, 3 } } };
    }

    static State initial()
    {
        return { initialRings(), 0 };
    }

    // The rings overlap in two slots, so a turn of one ring has to be mirrored into the other.
    static void syncSharedSlots(Rings& rings, bool leftTurned)
    {
        if (leftTurned) {
            rings.right[1] = rings.left[3];
            rings.right[7] = rings.left[5];
        } else {
            rings.left[3] = rings.right[1];
            rings.left[5] = rings.right[7];
        }
    }

    static void turnRing(Rings& rings, const std::string& move)
    {
        bool leftTurned = move[0] == 'l';
        Ring& ring = leftTurned ? rings.left : rings.right;

        if (move[1] == 'a') {
            std::rotate(ring.begin(), ring.begin() + 1, ring.end());
        } else {
            std::rotate(ring.begin(), ring.end() - 1, ring.end());
        }
        syncSharedSlots(rings, leftTurned);
    }

    // Gems are numbered 1-4 in the order of gemName().
    static bool isGemSolved(const Rings& rings, int gem)
    {
        const int slots[4] = { rings.left[0], rings.left[4], rings.right[0], rings.right[4] };
        for (int slot : slots) {
            if (slot != gem && slot != wildcard) {
                return false;
            }
        }
        return true;
    }

    // Returns false when the move is not one of the four ring turns.
    static bool apply(State& state, const std::string& move)
    {
        if (!contains(moves(), move)) {
            return false;
        }

        turnRing(state.rings, move);
        for (int gem = 1; gem <= gemCount; gem++) {
            if (isGemSolved(state.rings, gem)) {
                state.solvedMask |= 1u << (gem - 1);
            }
        }
        return true;
    }

    static bool isSolved(const State& state)
    {
        return state.solvedMask == (1u << gemCount) - 1;
    }

    static unsigned long long encode(const State& state)
    {
        unsigned long long key = state.solvedMask;
        for (int slot : state.rings.left) {
            key = key * 8 + slot;
        }
        for (int slot : state.rings.right) {
            key = key * 8 + slot;
        }
        return key;
    }
};
