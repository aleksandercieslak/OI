#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n { 0 };
    cin >> n;
    vector<vector<char>> image (n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        for (int j = 0; j < n; j++) {
            image[i][j] = a[j];
        }
    }
    vector<array<int, 4>> pcl;
    for (int x1 = 0; x1 < n; x1++) {
        for (int y1 = 0; y1 < n; y1++) {
            for (int x2 = x1; x2 < n; x2++) {
                for (int y2 = y1; y2 < n; y2++) {
                    vector<vector<bool>> vis (n, vector<bool>(n));
                    map<char, int> regions;
                    set<char> colors;
                    for (int i = y1; i <= y2; i++) {
                        for (int j = x1; j <= x2; j++) {
                            if (vis[i][j]) { continue; } 
                            stack<pair<int, int>> s;
                            s.push({i, j});
                            vis[i][j] = true;
                            colors.insert(image[i][j]);
                            if (colors.size() > 2) { break; }
                            regions[image[i][j]]++;
                            while (!s.empty()) {
                                int r { s.top().first }; 
                                int c { s.top().second };
                                s.pop();
                                colors.insert(image[r][c]);
                                if (colors.size() > 2) { break; }
                                if (r > y1 && !vis[r-1][c] && image[r-1][c] == image[r][c]) { s.push({r-1, c}); vis[r-1][c] = true; } 
                                if (r < y2 && !vis[r+1][c] && image[r+1][c] == image[r][c]) { s.push({r+1, c}); vis[r+1][c] = true; } 
                                if (c > x1 && !vis[r][c-1] && image[r][c-1] == image[r][c]) { s.push({r, c-1}); vis[r][c-1] = true; } 
                                if (c < x2 && !vis[r][c+1] && image[r][c+1] == image[r][c]) { s.push({r, c+1}); vis[r][c+1] = true; } 
                            }
                        }
                        if (colors.size() > 2) { break; }
                    }
                    if (colors.size() == 2) {
                        int f { 0 };
                        int s { 0 };
                        bool fi { true };
                        for (const auto& a : regions) {
                            if (fi) { f = a.second; fi = !fi; } 
                            else { s = a.second; }
                        }
                        if ((f == 1 && s >= 2) || (f >= 2 && s == 1)) {
                            pcl.push_back({x1, y1, x2, y2});
                        }
                    }
                }
            }
        }
    }
    int answer { 0 };
    for (int i = 0; i < static_cast<int>(pcl.size()); i++) {
        bool contained { false };
        for (int j = 0; j < static_cast<int>(pcl.size()); j++) {
            if (i == j) { continue; } 
            if (pcl[i][0] >= pcl[j][0] && pcl[i][1] >= pcl[j][1] && pcl[i][2] <= pcl[j][2] && pcl[i][3] <= pcl[j][3]) {
                contained = true;
                break;
            }
        }
        if (!contained) { answer++; }
    }
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
