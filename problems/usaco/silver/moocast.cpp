#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    cin >> numberOfCows;
    vector<array<int, 3>> cows (numberOfCows);
    for (auto& a : cows) {
        cin >> a[0] >> a[1] >> a[2];
    }
    vector<vector<int>> connections (numberOfCows);
    for (int i = 0; i < numberOfCows; i++) {
        for (int j = 0; j < numberOfCows; j++) {
            if (i != j) {
                int a { cows[i][0]-cows[j][0] }; 
                int b { cows[i][1]-cows[j][1] }; 
                if (a*a+b*b <= cows[i][2]*cows[i][2]) {
                    connections[i].push_back(j);
                }
            }
        }
    }
    int answer { 0 };
    for (int i = 0; i < numberOfCows; i++) {
        queue<int> bfsQueue;
        vector<bool> visited (numberOfCows);
        int rangeCounter { 0 };
        visited[i] = true;
        bfsQueue.push(i);
        while (!bfsQueue.empty()) {
            int current { bfsQueue.front() };
            bfsQueue.pop();
            for (auto a : connections[current]) {
                if (!visited[a]) {
                    visited[a] = true;
                    bfsQueue.push(a);
                }
            }
            rangeCounter++;
        }
        answer = max(answer, rangeCounter);
    }
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
