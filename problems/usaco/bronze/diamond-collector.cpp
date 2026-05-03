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
    int numberOfDiamonds { 0 };
    int difference { 0 };
    int amountOfDiamonds { 0 };
    cin >> numberOfDiamonds >> difference;
    vector<int> diamond (numberOfDiamonds);
    for (int i = 0; i < numberOfDiamonds; i++) {
        cin >> diamond[i];
    }
    sort(diamond.begin(), diamond.end(), [](int x, int y) { return x < y; });
    for (int i = 0; i < numberOfDiamonds-1; i += 2) {
        if (diamond[i] != diamond.back()) {
            if (diamond[i] - diamond[i+1] <= difference) {
                amountOfDiamonds += 2;
            } 
        }
    }
    cout << amountOfDiamonds << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}