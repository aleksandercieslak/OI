#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfRooms { 0 };
    int numberOfCows { 0 };
    int constantCows { 0 };
    int steps { 0 };
    int lowestAmountOfSteps { 99999999 };
    cin >> numberOfRooms;
    vector<int> space(numberOfRooms);
    for (int i = 0; i < numberOfRooms; i++) {
        cin >> space[i];
        constantCows += space[i];
    }
    for (int i = 0; i < numberOfRooms; i++) {
        steps = 0;
        numberOfCows = constantCows;       
        rotate(space.begin(), space.end() - 1, space.end());
        for (int j = 0; j < numberOfRooms; j++) {
        numberOfCows -= space[j];
        steps += numberOfCows;
        }
        lowestAmountOfSteps = min(lowestAmountOfSteps, steps);
    }
    cout << lowestAmountOfSteps << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}