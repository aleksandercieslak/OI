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
    int numberOfFlowers { 0 };
    cin >> numberOfFlowers;
    vector<int> petals (numberOfFlowers);
    for (int i = 0; i < numberOfFlowers; i++) {
        cin >> petals[i];
    }
    int answer { 0 };
    for (int i = 0; i < numberOfFlowers; i++) {
        for (int j = i; j < numberOfFlowers; j++) {
        int sum = reduce(petals.begin() + i, petals.begin() + j);
        int average = sum/(j-i);       
            if (count(petals.begin() + i, petals.begin() + j, average) > 0) {
                answer++;
            }
        }
    }
    cout << answer << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}