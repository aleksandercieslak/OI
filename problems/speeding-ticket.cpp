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
    int roadSegments { 0 };
    int cowSegments { 0 };
    int maxSpeeding { 0 };
    vector<int> road(100);
    vector<int> bessie(100);
    int it { 0 };
    cin >> roadSegments >> cowSegments;
    for (int i = 0; i < roadSegments; ++i) {
        int length { 0 };
        int speed { 0 };
        cin >> length >> speed;
        for (int j = 0; j < length; ++j) {
            road[it] = speed;
            ++it;
        }
    }
    it = 0;
    for (int i = 0; i < cowSegments; ++i) {
        int length { 0 };
        int speed { 0 };
        cin >> length >> speed;
        for (int j = 0; j < length; ++j) {
            bessie[it] = speed;
            ++it;
        }
    }
    for (int i = 0; i < 100; i++) {
        if (bessie[i] > road[i] && bessie[i] - road[i] > maxSpeeding) {
            maxSpeeding = bessie[i] - road[i];
        }
    }
    cout << maxSpeeding << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}