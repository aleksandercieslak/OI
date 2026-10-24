#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n { 0 };
    int b { 0 };
    cin >> n >> b;
    vector<int> snow (n);
    for (int& a : snow) {
        cin >> a;
    }
    deque<array<int, 3>> boots;
    for (int i = 0; i < b; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        boots.push_back({t1, t2, i});
    }
    int lastReachable { 0 };
    int disc { -1 };
    vector<array<int, 3>> oldBoots;
    vector<bool> vis (n);
    while (lastReachable != n-1) {
        disc++;
        int maxDepth { boots.front()[0] }; 
        int maxLength { boots.front()[1] };
        int no { boots.front()[2] };
        boots.pop_front();
        stack<int> s;
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                if (snow[i] <= maxDepth) {
                    s.push(i);
                    vis[i] = true;
                }
            }
        }
        if (oldBoots.empty()) { s.push(0); }
        while (!s.empty()) {
            int t { s.top() };  
            s.pop();
            for (int i = t+1; i <= min(t+maxLength, n-1); i++) {
                if (vis[i]) { continue; } 
                if (snow[i] <= maxDepth) {
                    vis[i] = true;
                    s.push(i);
                    lastReachable = max(lastReachable, i);
                }
            }
        }
        oldBoots.push_back({maxDepth, maxLength, no});
    }
    cout << disc << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
