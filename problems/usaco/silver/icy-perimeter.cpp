#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n { 0 };
    cin >> n;
    vector<vector<char>> grid (n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<bool>> vis (n, vector<bool>(n));
    int bestArea { 0 };
    int bestPerimeter { 0 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] || grid[i][j] == '.') { continue; }
            stack<pair<int, int>> s; 
            s.push({i, j});
            vis[i][j] = true;
            int area { 1 };
            int perimeter { 0 };
            while (!s.empty()) {
                int r { s.top().first };
                int c { s.top().second };
                s.pop();
                if (r == 0 || r == n-1) { perimeter++; }
                if (c == 0 || c == n-1) { perimeter++; }
                if (r != 0) {
                    if (grid[r-1][c] == '.') {
                        perimeter++;
                    }
                    else if (!vis[r-1][c]) {
                        area++;
                        s.push({r-1, c});
                        vis[r-1][c] = true;
                    }
                }
                if (r != n-1) {
                    if (grid[r+1][c] == '.') {
                        perimeter++;
                    }
                    else if (!vis[r+1][c]) {
                        area++;
                        s.push({r+1, c});
                        vis[r+1][c] = true;
                    }
                }
                if (c != 0) {
                    if (grid[r][c-1] == '.') {
                        perimeter++;
                    }
                    else if (!vis[r][c-1]) {
                        area++;
                        s.push({r, c-1});
                        vis[r][c-1] = true;
                    }
                }
                if (c != n-1) {
                    if (grid[r][c+1] == '.') {
                        perimeter++;
                    }
                    else if (!vis[r][c+1]) {
                        area++;
                        s.push({r, c+1});
                        vis[r][c+1] = true;
                    }
                }
            }
            if (area > bestArea) {
                bestArea = area;
                bestPerimeter = perimeter;
            }
            else if (area == bestArea) {
                bestPerimeter = min(bestPerimeter, perimeter);
            }
        }
    }
    cout << bestArea << " " << bestPerimeter << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
