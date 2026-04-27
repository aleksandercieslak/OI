#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    cin >> numberOfCows;
    vector<int> sequence (numberOfCows);
    vector<int> expected (numberOfCows);
    for (int i = 0; i < numberOfCows; i++) {
        cin >> sequence[i];
        sequence[i]--;
    }
    for (int i = 0; i < numberOfCows; i++) {
        cin >> expected[i];
        expected[i]--;
    }
    vector<bool> moved (numberOfCows);
    int moves { 0 };
    int j { 0 };
    for (int i = 0; i < numberOfCows; i++) {
        while (moved[sequence[j]] && j < numberOfCows) {
            j++;
        }
        if (sequence[j] == expected[i]) {
            j++;
        }
        else {
            moves++;
            moved[expected[i]] = true;
        }
    }
    cout << moves << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}