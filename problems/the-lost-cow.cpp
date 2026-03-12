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
    int positionJohn { 0 };
    int positionBessie { 0 };
    int direction { -1 };
    float lastMovement { -0.5f };
    int steps { 0 };
    cin >> positionJohn >> positionBessie;
    while (positionJohn != positionBessie) {
        lastMovement = 2 * direction * lastMovement;
        for (int i = positionJohn + lastMovement/abs(lastMovement); i != positionJohn + lastMovement + lastMovement/abs(lastMovement); i+=lastMovement/abs(lastMovement)) {
            ++steps;
            if (i == positionBessie) {
                cout << steps << "\n";
                return;
            }
        }
        steps += abs(lastMovement);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}