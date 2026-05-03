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
    vector<int> x (numberOfCows);
    vector<int> y (numberOfCows);
    for (int i = 0; i < numberOfCows; i++) {
        cin >> x[i] >> y[i];
    }
    int answer { 1000 };
    int smallestX = *min_element(x.begin(), x.end());
    int largestX = *max_element(x.begin(), x.end());
    int smallestY = *min_element(y.begin(), y.end());
    int largestY = *max_element(y.begin(), y.end());
    for (int i = smallestX-1; i <= largestX+1; i+=2) {
        for (int j = smallestY-1; j <= largestY+1; j+=2) {
            int topLeft { 0 };
            int topRight { 0 };
            int bottomLeft { 0 };
            int bottomRight { 0 };
            for (int k = 0; k < numberOfCows; k++) {
                if (x[k] > i) {
                    if (y[k] > j) {
                        topRight++;
                    }
                    else {
                        bottomRight++;
                    }
                }
                else {
                    if (y[k] > j) {
                        topLeft++;
                    }
                    else {
                        bottomLeft++;
                    }
                }
            }
            int current = max(max(topLeft, topRight), max(bottomLeft, bottomRight));
            answer = min(current, answer);
        }
    }
    cout << answer << "\n";   
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}