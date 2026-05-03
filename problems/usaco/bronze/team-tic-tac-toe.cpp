#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using pii = pair<int,int>;
using vi  = vector<int>;
using vl  = vector<ll>;

#define F first
#define S second
#define all(x)     (x).begin(),(x).end()
#define pb         push_back
#define rep(i,a,b) for(int i=(a);i<(b);i++)

const int INF  = 1e9;
const ll  LINF = 1e18;
const int MOD  = 1e9+7;

void solve() {
    vector<vector<char>> squares(3, vector<char> (3));
    set<char> solo;
    set<pair<char, char>> duo;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> squares[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        if (squares[i][0] == squares[i][1] && squares[i][0] == squares[i][2]) {
            solo.insert(squares[i][0]);
            continue;
        }
        else if (squares[i][0] == squares[i][1] || squares[i][0] == squares[i][2] || squares[i][1] == squares[i][2]) {
            duo.insert({min(squares[i][0], min(squares[i][1], squares[i][2])), max(squares[i][0], max(squares[i][1], squares[i][2]))});
        }
    }
    for (int i = 0; i < 3; i++) {
        if (squares[0][i] == squares[1][i] && squares[0][i] == squares[2][i]) {
            solo.insert(squares[0][i]);
            continue;
        }
        else if (squares[0][i] == squares[1][i] || squares[0][i] == squares[2][i] || squares[1][i] == squares[2][i]) {
            duo.insert({min(squares[0][i], min(squares[1][i], squares[2][i])), max(squares[0][i], max(squares[1][i], squares[2][i]))});
        }
    }
    if (squares[0][0] == squares[1][1] && squares[0][0] == squares[2][2]) {
        solo.insert(squares[0][0]);
    }
    else if (squares[0][0] == squares[1][1] || squares[0][0] == squares[2][2] || squares[1][1] == squares[2][2]) {
        duo.insert({min(squares[0][0], min(squares[1][1], squares[2][2])), max(squares[0][0], max(squares[1][1], squares[2][2]))});
    }
    if (squares[0][2] == squares[1][1] && squares[0][2] == squares[2][0]) {
        solo.insert(squares[0][2]);
    }
    else if (squares[0][2] == squares[1][1] || squares[0][2] == squares[2][0] || squares[1][1] == squares[2][0]) {
        duo.insert({min(squares[0][2], min(squares[1][1], squares[2][0])), max(squares[0][2], max(squares[1][1], squares[2][0]))});
    }
    cout << solo.size() << "\n" << duo.size() << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}