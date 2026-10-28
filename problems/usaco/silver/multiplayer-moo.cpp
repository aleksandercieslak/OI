#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n { 0 };
    cin >> n;
    vector<vector<int>> board (n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    vector<int> dy {-1, 1, 0, 0};
    vector<int> dx {0, 0, -1, 1};
    vector<vector<bool>> vis (n, vector<bool>(n));
    vector<vector<int>> reg (n, vector<int>(n));
    vector<int> size;
    int single { 0 };
    int count { -1 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j]) { continue; }  
            count++;
            reg[i][j] = count;
            stack<pair<int, int>> s;
            s.push({i, j});
            vis[i][j] = true;
            int area { 1 };
            while (!s.empty()) {
                int y { s.top().first }; 
                int x { s.top().second }; 
                s.pop();
                for (int d = 0; d < 4; d++) {
                    if (y+dy[d] < 0 || y+dy[d] > n-1 || x+dx[d] < 0 || x+dx[d] > n-1) { continue; }
                    if (vis[y+dy[d]][x+dx[d]]) { continue; }
                    if (board[y+dy[d]][x+dx[d]] != board[y][x]) { continue; }
                    s.push({y+dy[d], x+dx[d]});
                    vis[y+dy[d]][x+dx[d]] = true;
                    reg[y+dy[d]][x+dx[d]] = count;
                    area++;
                }
            }
            single = max(single, area);
            size.push_back(area);
        }
    }
    vector<array<int, 4>> adj;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int d = 0; d < 4; d++) {
                if (i+dy[d] < 0 || i+dy[d] > n-1 || j+dx[d] < 0 || j+dx[d] > n-1) { continue; }
                if (board[i][j] != board[i+dy[d]][j+dx[d]]) {
                    adj.push_back({
                        min(board[i][j], board[i+dy[d]][j+dx[d]]), 
                        max(board[i][j], board[i+dy[d]][j+dx[d]]),
                        reg[i][j],
                        reg[i+dy[d]][j+dx[d]]
                    });
                }
            }
        }
    }
    sort(adj.begin(), adj.end());
    vector<vector<int>> con (count+1);
    vector<int> mark (count+1, -1);
    int m { 0 };
    int ans { single };
    int total { static_cast<int>(adj.size()) };
    for (int i = 0; i < total; i++) {
        con[adj[i][2]].push_back(adj[i][3]);   
        con[adj[i][3]].push_back(adj[i][2]);   
        int j { i };
        while (j+1 < total && adj[j+1][0] == adj[i][0] && adj[j+1][1] == adj[i][1]) {
            j++; 
            con[adj[j][2]].push_back(adj[j][3]);   
            con[adj[j][3]].push_back(adj[j][2]);   
        }
        for (int k = i; k <= j; k++) {
            if (mark[adj[k][2]] == m) { continue; }
            stack<int> st;
            st.push(adj[k][2]);
            mark[adj[k][2]] = m;
            int area { size[adj[k][2]] };
            while (!st.empty()) {
                int t { st.top() }; 
                st.pop();
                for (const int& a : con[t]) {
                    if (mark[a] == m) { continue; }
                    st.push(a);
                    mark[a] = m;
                    area += size[a];
                }
            }
            ans = max(ans, area);
        } 
        for (int k = i; k <= j; k++) {
            con[adj[k][2]].clear();
            con[adj[k][3]].clear();
        }
        m++;
        i = j;
    }
    cout << single << "\n";
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
