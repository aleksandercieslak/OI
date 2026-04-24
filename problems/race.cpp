#include <bits/stdc++.h>
using namespace std;

void solve() {
    int raceLength { 0 };
    int numberOfTests { 0 };
    cin >> raceLength >> numberOfTests;
    vector<int> tests (numberOfTests);
    for (int i = 0; i < numberOfTests; i++) {
        cin >> tests[i];
    }
    for (int requiredSpeed : tests) {
        int distanceToFinish { raceLength };
        int steps { 0 };
        int currentSpeed { 0 };
        steps++;
        distanceToFinish--;
        currentSpeed++;
        while (distanceToFinish > 0) {
            if ((requiredSpeed+1+currentSpeed+1)*(currentSpeed-requiredSpeed+1)/2 < distanceToFinish || currentSpeed < requiredSpeed) {
                currentSpeed++;
                distanceToFinish -= currentSpeed;
            }
            else if ((requiredSpeed+1+currentSpeed)*(currentSpeed-requiredSpeed)/2 < distanceToFinish || currentSpeed < requiredSpeed) {
                distanceToFinish -= currentSpeed;
            }
            else {
                currentSpeed--;
                distanceToFinish -= currentSpeed;
            }
            steps++;
        }
        cout << steps << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}