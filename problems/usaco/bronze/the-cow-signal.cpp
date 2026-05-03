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
    int M = 0;
    int N = 0;
    int K = 0;
    cin >> M >> N >> K;
    vector<string> sheet (M);
    for (int i = 0; i < M; i++) {
        cin >> sheet[i];
    }
        for (int i = 0; i < M*K; i++) {
            for (int j = 0; j < N*K; j++) {
                cout << sheet[i/K][j/K];
            }
            cout << "\n";
        }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}