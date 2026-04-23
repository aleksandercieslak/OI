#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    cin >> numberOfCows;
    vector<int> cows (numberOfCows);
    for (int i = 0; i < numberOfCows; i++) {
        cin >> cows[i];
    }
    vector<int> sortedCows { cows };
    sort(sortedCows.begin(), sortedCows.end());
    int steps { -1 };
    for (int i = 0; i < numberOfCows; i++) {
        if (cows[i] != sortedCows[i]) { steps++; }
    }
    cout << steps << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}