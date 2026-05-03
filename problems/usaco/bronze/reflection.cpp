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

int canvasSize { 0 };
int numberOfUpdates { 0 };
vector<string> canvas (canvasSize);

int neededUpdates(int row, int column) {
    int paintedCells { 0 };
    if (canvas[row][column] == '#') {
        paintedCells++;
    }
    if (canvas[canvasSize - row - 1][column] == '#') {
        paintedCells++;
    }
    if (canvas[row][canvasSize - column - 1] == '#') {
        paintedCells++;
    }
    if (canvas[canvasSize - row - 1][canvasSize - column - 1] == '#') {
        paintedCells++;
    }
    return min(paintedCells, 4 - paintedCells);
}

void solve() {
    int answer { 0 };
    cin >> canvasSize >> numberOfUpdates;
    canvas.resize(canvasSize);
    vector<pair<int, int>> update (numberOfUpdates);
    for (int i = 0; i < canvasSize; i++) {
        cin >> canvas[i];
    }
    for (int i = 0; i < numberOfUpdates; i++) {
        cin >> update[i].first >> update[i].second;
    }
    for (int i = 0; i < canvasSize/2; i++) {
        for (int j = 0; j < canvasSize/2; j++) {
            answer += neededUpdates(i, j);
        }
    }
    cout << answer << "\n";
    answer = 0;
    for (int k = 0; k < numberOfUpdates; k++) {
        update[k].first--;
        update[k].second--;
        if (canvas[update[k].first][update[k].second] == '#') {
            canvas[update[k].first][update[k].second] = '.';
        }
        else { canvas[update[k].first][update[k].second] = '#'; }
        for (int i = 0; i < canvasSize/2; i++) {
            for (int j = 0; j < canvasSize/2; j++) {
                answer += neededUpdates(i, j);
            }
        }
        cout << answer << "\n";
        answer = 0;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}