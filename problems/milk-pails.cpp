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
    int small { 0 };
    int medium { 0 };
    int big { 0 };
    int milk { 0 };
    int maximum { 0 };
    cin >> small >> medium >> big;
    for (int first = 0; first <= big; first++) {
        if (first*small > big) { break; }
        for (int second = 0; second <= big; second++) {
            milk = first*small + second*medium;
            if (milk > big) { break; }
            maximum = max(maximum, milk);
        }
    }
    cout << maximum << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}