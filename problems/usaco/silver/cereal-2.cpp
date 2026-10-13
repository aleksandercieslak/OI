#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n { 0 };
    int m { 0 };
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph (m);
    vector<int> favorite (n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a-1].push_back({b-1, i});
        graph[b-1].push_back({a-1, i});
        favorite[i] = a-1;
    }
    vector<bool> visited (m);
    vector<bool> visited2 (m);
    vector<bool> isTree (n); 
    vector<bool> placed (n); 
    int hungryCows { 0 }; 
    vector<int> permutation;
    for (int i = 0; i < m; i++) {
        if (visited[i]) { continue; }
        vector<int> conn;
        stack<int> dfsStack;
        dfsStack.push(i);
        visited[i] = true;
        conn.push_back(i);
        int cows { 0 };
        int cereal { 0 };
        while (!dfsStack.empty()) {
            int temp { dfsStack.top() }; 
            dfsStack.pop();
            cereal++;
            for (const auto& a : graph[temp]) {
                cows++;
                if (!visited[a.first]) {
                    dfsStack.push(a.first);
                    visited[a.first] = true;
                    isTree[a.second] = true;
                    conn.push_back(a.first);
                }
            }
        }
        cows /= 2;
        hungryCows += abs(min(0, cereal-cows));
        int extra { -1 };
        for (const int& v : conn) {
            for (const auto& a : graph[v]) {
                if (!isTree[a.second]) { extra = a.second; }
            }
        }
        int root { i };
        if (extra != -1) {
            root = favorite[extra];
            permutation.push_back(extra);
            placed[extra] = true;
        }
        dfsStack.push(root);
        visited2[root] = true;
        while (!dfsStack.empty()) {
            int temp { dfsStack.top() }; 
            dfsStack.pop();
            for (const auto& a : graph[temp]) {
                if (placed[a.second] || visited2[a.first]) {
                    continue;
                }
                visited2[a.first] = true;
                placed[a.second] = true;
                permutation.push_back(a.second);
                dfsStack.push(a.first);
            }
        }
    } 
    for (int i = 0; i < n; i++) {
        if (!placed[i]) {
            permutation.push_back(i);
        } 
    }
    cout << hungryCows << "\n";
    for (const int& p : permutation) {
        cout << p+1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
