#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfDiamonds { 0 };
    int k { 0 };
    cin >> numberOfDiamonds >> k;
    vector<int> diamonds (numberOfDiamonds);
    for (int i = 0; i < numberOfDiamonds; i++) {
        cin >> diamonds[i];
    }
    sort(diamonds.begin(), diamonds.end());
    unordered_map<int, int> reach;
    for (int i = 0; i < numberOfDiamonds; i++) {
        int j { i };
        while (j < numberOfDiamonds && diamonds[j]-diamonds[i] <= k) { j++; }
        reach[i] = j-i;
    }
    unordered_map<int, int> maxReach;
    maxReach[numberOfDiamonds] = 0;
    for (int i = numberOfDiamonds-1; i >= 0; i--) {
        maxReach[i] = max(reach[i], maxReach[i+1]);
    }
    int answer { 0 };
    for (int i = 0; i < numberOfDiamonds; i++) {
        answer = max(answer, reach[i] + maxReach[i+reach[i]]);
    }
    cout << answer << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}