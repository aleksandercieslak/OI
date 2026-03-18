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
    string point;
    vector<pair<char, char>> crossing;
    cin >> point;
    int firstPosition { 52 };
    int secondPosition { 0 };
    for (int i = 0; i < 52; i++) {
        for (int k = 0; k < 52; k++) {
            if (point[k] == point[i] && k > firstPosition) {
                secondPosition = k;
            }
            else if (point[k] == point[i]) {
                firstPosition = k;
            }
        }
        if (count(point.begin() + i, point.end(), point[i]) > 1) {
            for (int j = i + 1; j < 52; j++) {
                if (point[j] == point[i]) {
                    break;
                }
                if (count(point.begin() + firstPosition, point.begin() + secondPosition, point[j]) == 1) {
                    int one = min(point[j], point[i]);
                    int two = max(point[j], point[i]);
                    crossing.push_back({one, two});
                }
            }
        }
        firstPosition = 52;
        secondPosition = 0;
    }
    cout << crossing.size()/2 << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}