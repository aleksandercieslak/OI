#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    int numberOfConnections { 0 };
    cin >> numberOfCows >> numberOfConnections;
    vector<pair<int, int>> cows (numberOfCows);
    for (auto& a : cows) {
        cin >> a.first >> a.second;
    }
    vector<vector<int>> connections (numberOfCows);
    for (int i = 0; i < numberOfConnections; i++) {
        int a, b;
        cin >> a >> b;
        connections[a-1].push_back(b-1);
        connections[b-1].push_back(a-1);
    }
    vector<array<int, 4>> coordinates;
    vector<bool> visited (numberOfCows);
    for (int i = 0; i < numberOfCows; i++) {
        if (visited[i]) { continue; }
        else {
            stack<int> dfsStack;
            visited[i] = true;
            dfsStack.push(i);
            int left { INT_MAX };
            int right { 0 };
            int top { 0 };
            int bottom { INT_MAX };
            while (!dfsStack.empty()) {
                int temp { dfsStack.top() };
                dfsStack.pop();
                left = min(left, cows[temp].first); 
                right = max(right, cows[temp].first); 
                top = max(top, cows[temp].second); 
                bottom = min(bottom, cows[temp].second); 
                for (const auto& a : connections[temp]) {
                    if (!visited[a]) {
                        dfsStack.push(a);
                        visited[a] = true;
                    }
                }
            }
            coordinates.push_back({left, right, top, bottom});
        }
    }
    int answer { INT_MAX };
    for (const auto& a : coordinates) {
        int horizontal { abs(a[0]-a[1]) };
        int vertical { abs(a[2]-a[3]) };
        answer = min(answer, 2*(horizontal+vertical));
    }
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
