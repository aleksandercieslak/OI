#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> positions, vector<array<int, 3>> wormholes, int middle) {
    while (!wormholes.empty() && wormholes.back()[2] < wormholes[middle][2]) {
        wormholes.pop_back();
    }
    vector<vector<int>> connections (positions.size());
    for (const auto& a : wormholes) {
        connections[a[0]].push_back(a[1]); 
        connections[a[1]].push_back(a[0]); 
    }
    vector<int> visited (positions.size());
    int tag { 1 };
    for (int i = 0; i < static_cast<int>(positions.size()); i++) {
        if (visited[i] == 0) {
            stack<int> dfsStack;
            dfsStack.push(i);
            visited[i] = tag;
            while (!dfsStack.empty()) {
                int temp { dfsStack.top() };
                dfsStack.pop();
                for (const auto& a : connections[temp]) {
                    if (visited[a] == 0) {
                        dfsStack.push(a);
                        visited[a] = tag;
                    }
                }
            }
            tag++;
        }
    }
    bool possible { true };
    for (int i = 0; i < static_cast<int>(positions.size()); i++) {
        if (visited[i] != visited[positions[i]]) {
            possible = false;
        } 
    }
    return possible;
}
void solve() {
    int numberOfCows { 0 };
    int numberOfWormholes { 0 };
    cin >> numberOfCows >> numberOfWormholes;
    vector<int> positions (numberOfCows);
    for (int i = 0; i < numberOfCows; i++) {
        cin >> positions[i];
        positions[i]--;
    }
    vector<int> sorted { positions };
    sort(sorted.begin(), sorted.end());
    if (sorted == positions) {
        cout << -1 << "\n";
    }
    else {
        vector<array<int, 3>> wormholes (numberOfWormholes);
        for (int i = 0; i < numberOfWormholes; i++) {
            cin >> wormholes[i][0] >> wormholes[i][1] >> wormholes[i][2];
            wormholes[i][0]--;
            wormholes[i][1]--;
        }
        int left { 0 };
        int right { numberOfWormholes-1 };
        sort(wormholes.begin(), wormholes.end(), [](const auto& a, const auto& b) { return a[2] > b[2]; });
        while (left < right) {
            int middle { (left+right-1)/2 };
            if (dfs(positions, wormholes, middle)) {
                right = middle;
            }
            else {
                left = middle + 1;
            }
        }
        cout << wormholes[left][2] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
