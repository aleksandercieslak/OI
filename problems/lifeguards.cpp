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
    int numberOfLifeguards { 0 };
    cin >> numberOfLifeguards;
    vector<pair<int, int>> shifts (numberOfLifeguards);
    vector<int> minutes (1000);
    int worthCounter { 0 };
    int maxWorth { 0 };
    int answer { 0 };
    for (int i = 0; i < numberOfLifeguards; i++) {
        cin >> shifts[i].first >> shifts[i].second;
        for (int j = shifts[i].first; j < shifts[i].second; j++) {
            minutes[j]++;
        }
    }
    int coveredMinutes = 1000 - count(minutes.begin(), minutes.end(), 0);
    for (int i = 0; i < numberOfLifeguards; i++) {
        for (int j = shifts[i].first; j < shifts[i].second; j++) {
            if (minutes[j] > 1) {
                worthCounter++;
            }
        }
        if (worthCounter > maxWorth) {
            maxWorth = worthCounter;
            answer = coveredMinutes - (shifts[i].second - shifts[i].first) + worthCounter;
        }
        worthCounter = 0;
    }
    cout << answer << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}