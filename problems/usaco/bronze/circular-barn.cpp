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
    int numberOfRooms { 0 };
    int numberOfCows { 0 };
    int constantCows { 0 };
    int steps { 0 };
    int lowestAmountOfSteps { 99999999 };
    cin >> numberOfRooms;
    vector<int> space(numberOfRooms);
    for (int i = 0; i < numberOfRooms; i++) {
        cin >> space[i];
        constantCows += space[i];
    }
    for (int i = 0; i < numberOfRooms; i++) {
        steps = 0;
        numberOfCows = constantCows;       
        rotate(space.begin(), space.end() - 1, space.end());
        for (int j = 0; j < numberOfRooms; j++) {
        numberOfCows -= space[j];
        steps += numberOfCows;
        }
        lowestAmountOfSteps = min(lowestAmountOfSteps, steps);
    }
    cout << lowestAmountOfSteps << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}