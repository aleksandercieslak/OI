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
    int numberOfCows { 0 };
    cin >> numberOfCows;
    vector<int> bucketsInUse(1001);
    int largestAmount { 0 };
    for (int i = 0; i < numberOfCows; i++) {
        int startTime { 0 };
        int endTime { 0 };
        int buckets { 0 };
        cin >> startTime >> endTime >> buckets;
        for (int j = startTime; j < endTime + 1; j++) {
            bucketsInUse[j] += buckets;
            if (bucketsInUse[j] > largestAmount) {
                largestAmount = bucketsInUse[j];
            }
        }
    }
    cout << largestAmount << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}