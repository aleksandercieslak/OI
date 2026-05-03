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
    int amountOfCows { 0 };
    cin >> amountOfCows;
    vector<int> cows(amountOfCows);
    vector<int> numbers(amountOfCows);
    for (int i = 0; i < amountOfCows; i++) {
        cin >> numbers[i];
    }
    for (int i = 0; i < amountOfCows; i++) {
        cin >> cows[i];
    }
    for (int i = 0; i < 3; i++) {
        vector<int> copy(amountOfCows);
        for (int j = 0; j < amountOfCows; j++) {
            copy[j] = cows[numbers[j] - 1];
        }
        cows = copy;
    }
    for (int i = 0; i < amountOfCows; i++) {
        cout << cows[i] << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}