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
    int numberOfIntegers { 0 };
    int high { 0 };
    cin >> numberOfIntegers;
    vector<pair<int, int>> coordinates ( numberOfIntegers );
    for (int i = 0; i < numberOfIntegers; i++) {
        cin >> coordinates[i].first;
    }
    for (int i = 0; i < numberOfIntegers; i++) {
        cin >> coordinates[i].second;
    }
    for (int i = 0; i < numberOfIntegers; i++) {
        for (int j = 0; j < numberOfIntegers; j++) {
            int x = abs(coordinates[i].first - coordinates[j].first);
            int y = abs(coordinates[i].second - coordinates[j].second);
            high = max(high, x*x + y*y);
        }
    }
    cout << high << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}