#include <bits/stdc++.h>
using namespace std;

int n { 0 };
int m { 0 };
vector<vector<int>> elev;
vector<vector<bool>> way;
pair<int, int> coords;
int total { 0 };

bool pos(int lim) {
    vector<vector<bool>> vis (elev.size(), vector<bool>(elev[0].size())); 
    stack<pair<int, int>> s; 
    s.push({coords.first, coords.second});
    vis[coords.first][coords.second] = true;
    int counter { 0 };
    while (!s.empty()) {
        int r { s.top().first }; 
        int c { s.top().second };
        s.pop();
        if (way[r][c]) { counter++; }
        if (r != 0 && !vis[r-1][c] && abs(elev[r][c]-elev[r-1][c]) <= lim) { s.push({r-1, c}); vis[r-1][c] = true; }
        if (r != n-1 && !vis[r+1][c] && abs(elev[r][c]-elev[r+1][c]) <= lim) { s.push({r+1, c}); vis[r+1][c] = true; }
        if (c != 0 && !vis[r][c-1] && abs(elev[r][c]-elev[r][c-1]) <= lim) { s.push({r, c-1}); vis[r][c-1] = true; }
        if (c != m-1 && !vis[r][c+1] && abs(elev[r][c]-elev[r][c+1]) <= lim) { s.push({r, c+1}); vis[r][c+1] = true; }
    }
    if (counter == total) {
        return true;
    }
    return false;
}

void solve() {
    cin >> n >> m;
    elev.resize(n, vector<int>(m));
    way.resize(n, vector<bool>(m));
    int me { 0 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> elev[i][j];
            me = max(me, elev[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int t;
            cin >> t;
            if (t == 1) {
                way[i][j] = true;
                coords = {i, j};
                total++;
            }
            else {
                way[i][j] = false;
            }
        }
    }
    int l { 0 };
    int h { me };
    while (l < h) {
        int mid { l+(h-l)/2 }; 
        if (pos(mid)) {
            h = mid;
        } 
        else {
            l = mid+1;
        }
    }
    cout << l << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
