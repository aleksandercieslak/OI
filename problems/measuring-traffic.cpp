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
    pair<int, int> postRange {0, 1000};
    pair<int, int> priorRange {0, 1000};
    int numberOfMiles { 0 };
    cin >> numberOfMiles;

    struct Sensor {
        string state;
        int lowRange;
        int highRange;
    };

    vector<Sensor> sensors(numberOfMiles);
    
    for (int i = 0; i < numberOfMiles; i++) {
        cin >> sensors[i].state >> sensors[i].lowRange >> sensors[i].highRange;
    }

    for (int i = numberOfMiles-1; i >= 0; i--) {
        if (sensors[i].state == "none") {
            priorRange.first = max(priorRange.first, sensors[i].lowRange);
            priorRange.second = min(priorRange.second, sensors[i].highRange);
        }
        if (sensors[i].state == "on") {
            priorRange.first -= sensors[i].highRange;
            priorRange.second -= sensors[i].lowRange;
        }
        if (sensors[i].state == "off") {
            priorRange.first += sensors[i].lowRange;
            priorRange.second += sensors[i].highRange;
        }
    }
    cout << priorRange.first << " " << priorRange.second << "\n";


    for (int i = 0; i < numberOfMiles; i++) {
        if (sensors[i].state == "none") {
            postRange.first = max(postRange.first, sensors[i].lowRange);
            postRange.second = min(postRange.second, sensors[i].highRange);
        }
        if (sensors[i].state == "on") {
            postRange.first += sensors[i].lowRange;
            postRange.second += sensors[i].highRange;
        }
        if (sensors[i].state == "off") {
            postRange.first -= sensors[i].highRange;
            postRange.second -= sensors[i].lowRange;
        }
    }
    cout << postRange.first << " " << postRange.second << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}