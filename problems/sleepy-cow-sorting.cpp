#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    cin >> numberOfCows;
    vector<int> cows (numberOfCows);
    for (int i = 0; i < numberOfCows; i++) {
        cin >> cows[i];
    }
    int answer { 0 };
    for (int i = 0; i < numberOfCows-1; i++) {
        if (cows[i] > cows[i+1]) {
            answer = i+1;
        }
    }
    cout << answer << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}