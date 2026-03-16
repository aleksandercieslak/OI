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
    int liars { 0 };
    int firstIndex { 0 };
    long long secondIndex { 1000000000 };
    vector<pair<char, int>> cow (numberOfCows);
    for (int i = 0; i < numberOfCows; i++) {
        cin >> cow[i].first >> cow[i].second;
    }
    for (int i = 0; i < numberOfCows; i++) {
        if (cow[i].first == 'L' && cow[i].second <= firstIndex) {
            liars++;
        }
        else if (cow[i].first == 'G' && cow[i].second >= secondIndex) {
            liars++;
        }
        else if (cow[i].first == 'L' && cow[i].second > firstIndex) {
            secondIndex = cow[i].second;
        }
        else if (cow[i].first == 'G' && cow[i].second < secondIndex) {
            firstIndex = cow[i].second;
        }
    }
    cout << liars << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}