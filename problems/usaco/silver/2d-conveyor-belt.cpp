#include <bits/stdc++.h>
using namespace std;

int n { 0 };
int q { 0 };

vector<int> dy {-1, 1, 0, 0};
vector<int> dx {0, 0, -1, 1};

bool valid(int y, int x) {
    if (y < 0 || y > n-1 || x < 0 || x > n-1) { return false; }
    return true;
}

bool isUsable(vector<vector<char>>& board, vector<vector<bool>>& usable, int y, int x) {
    char dir { board[y][x] };
    if (dir == '?' && (y == 0 || y == n-1 || x == 0 || x == n-1)) { return true; }
    if ((dir == '?' || dir == 'L') && ((valid(y, x-1) && usable[y][x-1]) || !valid(y, x-1))) {
        return true;
    }
    if ((dir == '?' || dir == 'R') && ((valid(y, x+1) && usable[y][x+1]) || !valid(y, x+1))) {
        return true;
    }
    if ((dir == '?' || dir == 'U') && ((valid(y-1, x) && usable[y-1][x]) || !valid(y-1, x))) {
        return true;
    }
    if ((dir == '?' || dir == 'D') && ((valid(y+1, x) && usable[y+1][x]) || !valid(y+1, x))) {
        return true;
    }
    return false;
}

void ff(vector<vector<char>>& board, vector<vector<bool>>& usable, int& usableCells, int y, int x) {
    if (!valid(y, x) || !isUsable(board, usable, y, x) || usable[y][x]) { return; }
    usableCells++;
    stack<pair<int, int>> st;
    st.push({y, x});
    usable[y][x] = true;
    while (!st.empty()) {
        int r { st.top().first }; 
        int c { st.top().second }; 
        st.pop();
        for (int d = 0; d < 4; d++) {
            if (!valid(r+dy[d], c+dx[d]) || !isUsable(board, usable, r+dy[d], c+dx[d]) || usable[r+dy[d]][c+dx[d]]) { continue; }
            usable[r+dy[d]][c+dx[d]] = true;
            st.push({r+dy[d], c+dx[d]});
            usableCells++;
        }
    }
}

struct Info {
    int y;
    int x;
    char dir;
};

void solve() {
    cin >> n >> q;
    vector<Info> queries (q);
    vector<vector<char>> board (n, vector<char>(n, '?'));
    for (auto& a : queries) {
        cin >> a.y >> a.x >> a.dir;
        a.y--;
        a.x--;
        board[a.y][a.x] = a.dir;
    }
    vector<vector<bool>> usable (n, vector<bool>(n));
    int usableCells { 0 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ff(board, usable, usableCells, i, j);
        }
    }         
    vector<int> ans;
    ans.push_back(n*n-usableCells);
    for (int i = 0; i < q-1; i++) {
        board[queries.back().y][queries.back().x] = '?';
        ff(board, usable, usableCells, queries.back().y, queries.back().x);
        queries.pop_back();
        ans.push_back(n*n-usableCells);
    }
    for (int i = q-1; i >= 0; i--) {
        cout << ans[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
