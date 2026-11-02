#pragma once

#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// Breadth-first search over a puzzle's states. Every puzzle provides:
//   State, name(), moves(), initial(), apply(state, move), isSolved(state), encode(state)
// Identical states are merged, so the search stays small even at 15 moves, and it
// reports every shortest solution (up to maxPrint of them) rather than just one.
template <class Puzzle>
void bruteforce(int maxMoves, size_t maxPrint)
{
    typedef typename Puzzle::State State;
    typedef unsigned long long Key;

    struct Edge {
        Key from;
        size_t move;
    };
    struct Node {
        State state;
        int depth;
        unsigned long long paths;
        std::vector<Edge> parents;
    };

    const std::vector<std::string> moves = Puzzle::moves();
    std::unordered_map<Key, Node> nodes;

    State start = Puzzle::initial();
    Key startKey = Puzzle::encode(start);
    nodes[startKey] = Node { start, 0, 1, {} };

    std::vector<Key> frontier = { startKey };
    std::vector<Key> solved;
    int depth = 0;

    while (solved.empty() && depth < maxMoves && !frontier.empty()) {
        std::vector<Key> next;
        for (Key key : frontier) {
            State state = nodes[key].state;
            unsigned long long paths = nodes[key].paths;

            for (size_t i = 0; i < moves.size(); i++) {
                State after = state;
                if (!Puzzle::apply(after, moves[i])) {
                    continue;
                }

                Key afterKey = Puzzle::encode(after);
                auto found = nodes.find(afterKey);
                if (found == nodes.end()) {
                    nodes[afterKey] = Node { after, depth + 1, 0, {} };
                    next.push_back(afterKey);
                    if (Puzzle::isSolved(after)) {
                        solved.push_back(afterKey);
                    }
                } else if (found->second.depth != depth + 1) {
                    continue;
                }

                Node& node = nodes[afterKey];
                node.paths += paths;
                node.parents.push_back(Edge { key, i });
            }
        }
        frontier = next;
        depth++;
    }

    std::cout << Puzzle::name() << ": ";
    if (solved.empty()) {
        std::cout << "no solution within " << maxMoves << " moves (" << nodes.size()
                  << " states searched)" << std::endl
                  << std::endl;
        return;
    }

    unsigned long long total = 0;
    for (Key key : solved) {
        total += nodes[key].paths;
    }
    std::cout << "shortest solution is " << depth << " moves, " << total << " solution"
              << (total == 1 ? "" : "s") << " of that length (" << nodes.size()
              << " states searched)" << std::endl;

    std::vector<size_t> suffix;
    size_t printed = 0;
    std::function<void(Key)> walk = [&](Key key) {
        if (printed >= maxPrint) {
            return;
        }
        const Node& node = nodes[key];
        if (node.depth == 0) {
            std::cout << "  ";
            for (auto move = suffix.rbegin(); move != suffix.rend(); ++move) {
                std::cout << moves[*move] << " ";
            }
            std::cout << std::endl;
            printed++;
            return;
        }
        for (const Edge& edge : node.parents) {
            suffix.push_back(edge.move);
            walk(edge.from);
            suffix.pop_back();
        }
    };
    for (Key key : solved) {
        walk(key);
    }
    if (total > printed) {
        std::cout << "  ... and " << total - printed << " more" << std::endl;
    }
    std::cout << std::endl;
}
