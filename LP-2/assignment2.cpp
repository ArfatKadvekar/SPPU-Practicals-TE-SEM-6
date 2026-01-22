#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Print board
void printBoard(const vector<int>& b) {
    for (int i = 0; i < 9; i++) {
        if (b[i] == 0) cout << "_ ";
        else cout << b[i] << " ";
        if (i % 3 == 2) cout << "\n";
    }
    cout << "-----\n";
}

// Manhattan distance
int manhattan(const vector<int>& state, const vector<int>& goal) {
    int dist = 0;

    for (int tile = 1; tile <= 8; tile++) {
        int si, gi;
        for (int i = 0; i < 9; i++) {
            if (state[i] == tile) si = i;
            if (goal[i] == tile)  gi = i;
        }
        dist += abs((si / 3) - (gi / 3)) + abs((si % 3) - (gi % 3));
    }
    return dist;
}

int main() {
    vector<int> current = {
        2, 8, 3,
        1, 6, 4,
        7, 0, 5
    };

    vector<int> goal = {
        1, 2, 3,
        8, 0, 4,
        7, 6, 5
    };

    int g = 0;

    cout << "Initial State:\n";
    printBoard(current);

    while (current != goal) {
        int blank;
        for (int i = 0; i < 9; i++)
            if (current[i] == 0) blank = i;

        vector<vector<int>> neighbors;

        // LEFT
        if (blank % 3 != 0) {
            vector<int> t = current;
            swap(t[blank], t[blank - 1]);
            neighbors.push_back(t);
        }
        // RIGHT
        if (blank % 3 != 2) {
            vector<int> t = current;
            swap(t[blank], t[blank + 1]);
            neighbors.push_back(t);
        }
        // UP
        if (blank >= 3) {
            vector<int> t = current;
            swap(t[blank], t[blank - 3]);
            neighbors.push_back(t);
        }
        // DOWN
        if (blank < 6) {
            vector<int> t = current;
            swap(t[blank], t[blank + 3]);
            neighbors.push_back(t);
        }

        int bestF = INT_MAX;
        vector<int> bestState;

        for (auto& n : neighbors) {
            int h = manhattan(n, goal);
            int f = (g + 1) + h;

            if (f < bestF) {
                bestF = f;
                bestState = n;
            }
        }

        current = bestState;
        g++;

        cout << "Iteration " << g << " (f = " << bestF << "):\n";
        printBoard(current);
    }

    cout << "Goal Reached in " << g << " moves.\n";
    return 0;
}
