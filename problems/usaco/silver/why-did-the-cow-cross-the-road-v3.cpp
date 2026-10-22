#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n { 0 };
    int ro { 0 };
    int k { 0 };
    cin >> n >> ro >> k;
    set<array<int, 4>> roads;
    for (int i = 0; i < ro; i++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        roads.insert({y1-1, x1-1, y2-1, x2-1});
        roads.insert({y2-1, x2-1, y1-1, x1-1});
    }
    vector<vector<bool>> cow (n, vector<bool>(n));
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        cow[a-1][b-1] = true;
    }
    vector<int> dx {-1, 1, 0, 0};
    vector<int> dy {0, 0, -1, 1};
    int answer { 0 };
    int rest { k };
    vector<vector<bool>> vis (n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j]) { continue; }
            stack<pair<int, int>> s;
            s.push({i, j});
            vis[i][j] = true;
            int counter { 0 }; 
            while (!s.empty()) {
                int r { s.top().first }; 
                int c { s.top().second }; 
                s.pop();
                if (cow[r][c]) { counter++; }
                for (int d = 0; d < 4; d++) {
                    int nx { c+dx[d] }; 
                    int ny { r+dy[d] }; 
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) { continue; }
                    if (vis[ny][nx]) { continue; }
                    if (roads.count({r, c, ny, nx}) != 0) { continue; }
                    s.push({ny, nx});
                    vis[ny][nx] = true;
                }
            }
            rest -= counter;
            answer += counter*rest;
        }
    }
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
