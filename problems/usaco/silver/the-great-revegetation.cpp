#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n { 0 };
    int m { 0 };
    cin >> n >> m;
    vector<vector<pair<char, int>>> adj (n);
    for (int i = 0; i < m; i++) {
        char t;
        int a, b;
        cin >> t >> a >> b;
        adj[a-1].push_back({t, b-1});
        adj[b-1].push_back({t, a-1});
    }
    int decisions { 0 };
    vector<bool> vis (n);
    vector<bool> isBlack (n);
    bool possible { true };
    for (int i = 0; i < n; i++) {
        if (vis[i]) { continue; } 
        decisions++;
        stack<int> dfsStack;
        vis[i] = true;
        isBlack[i] = true;
        dfsStack.push(i);
        while (!dfsStack.empty()) {
            int temp { dfsStack.top() }; 
            dfsStack.pop();
            for (const auto& a : adj[temp]) {
                if (vis[a.second] == true) {
                    if (a.first == 'S' && isBlack[a.second] != isBlack[temp]) {
                        possible = false;
                        break;
                    }
                    else if (a.first == 'D' && isBlack[a.second] == isBlack[temp]) {
                        possible = false;
                        break;
                    }
                    else {
                        continue;
                    }
                }
                vis[a.second] = true;
                dfsStack.push(a.second);
                if (a.first == 'S') {
                    isBlack[a.second] = isBlack[temp];
                }
                else if (a.first == 'D') {
                    isBlack[a.second] = !isBlack[temp];
                }
            }
            if (!possible) { break; }
        }
        if (!possible) { break; }
    }
    decisions *= 2;
    string answer;
    answer = bitset<8>(decisions).to_string();
    auto firstOne { answer.find_first_not_of('0') };
    if (firstOne == string::npos) {
        cout << 0 << "\n";
    }
    else {
        cout << answer.substr(firstOne) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
