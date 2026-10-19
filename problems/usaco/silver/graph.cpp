#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n { 0 };
    int m { 0 };
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj (n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a-1].push_back({c, b-1});
        adj[b-1].push_back({c, a-1});
    }
    vector<bool> visited (n);
    vector<double> val (n);
    bool ok { true };
    for (int i = 0; i < n; i++) {
        if (visited[i]) { continue; }
        double best { INT_MAX };
        double starter { 0 };
        int fails { 0 };
        for (double v = -2; v <= 2; v+=0.5) {
            vector<bool> visited2 (n);
            vector<double> val2 (n);
            double total { 0 };
            visited2[i] = true; 
            val2[i] = v;
            total += abs(v);
            stack<int> dfsStack2;
            dfsStack2.push(i);
            bool possible { true };
            while (!dfsStack2.empty()) {
                int temp { dfsStack2.top() }; 
                dfsStack2.pop();
                for (const auto& a : adj[temp]) {
                    if (visited2[a.second]) {
                        if (val2[a.second] != a.first-val2[temp]) {
                            possible = false; 
                            fails++;
                            break;
                        }
                        else { continue; }
                    }
                    else {
                        dfsStack2.push(a.second);
                        visited2[a.second] = true;
                        val2[a.second] = a.first-val2[temp];
                        total += abs(val2[a.second]);
                    }
                }
                if (!possible) { break; }
            }
            if (!possible) { continue; }
            if (total < best) {
                best = total;
                starter = v; 
            }
        }
        visited[i] = true;  
        stack<int> dfsStack;
        dfsStack.push(i);
        val[i] = starter;
        while (!dfsStack.empty()) {
            int t { dfsStack.top() }; 
            dfsStack.pop();
            for (const auto& a : adj[t]) {
                if (visited[a.second]) { continue; }
                visited[a.second] = true;
                dfsStack.push(a.second);
                val[a.second] = a.first-val[t];
            }
        }
        if (fails == 9) { ok = false; }
    }
    if (ok == false) {
        cout << "NO" << "\n";
    }
    else {
        cout << "YES" << "\n";
        for (int i = 0; i < n; i++) {
            if (i < n-1) { cout << val[i] << " "; }
            else { cout << val[i] << "\n"; }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
