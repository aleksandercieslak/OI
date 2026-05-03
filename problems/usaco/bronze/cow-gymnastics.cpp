#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    int numberOfSessions { 0 };
    cin >> numberOfSessions >> numberOfCows;
    vector<vector<int>> ranking (numberOfSessions, vector<int> (numberOfCows));
    for (int i = 0; i < numberOfSessions; i++) {
        for (int j = 0; j < numberOfCows; j++) {
            cin >> ranking[i][j];
        }
    }
    int sessions { 0 };
    int counter { 0 };
    for (int i = 1; i <= numberOfCows-1; i++) {
        for (int j = i+1; j <= numberOfCows; j++) {
            for (int k = 0; k < numberOfSessions; k++) {
                auto It1 = find(ranking[k].begin(), ranking[k].end(), i) - ranking[k].begin();
                auto It2 = find(ranking[k].begin(), ranking[k].end(), j) - ranking[k].begin();
                if (It1 < It2) {
                    sessions++;
                } 
            }
            if (sessions == numberOfSessions || sessions == 0) {
                counter++;
            }
            sessions = 0;
        }
    }
    cout << counter << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}