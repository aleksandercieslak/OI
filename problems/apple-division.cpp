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

void search(vector<int>& container, vector<int>& subset, int k, int weight, int& answer) {
    if (k == static_cast<int>(container.size())) {
        int subsetSum = subset.empty() ? 0 : reduce(subset.begin(), subset.end());
        answer = min(answer, abs(weight-2*subsetSum));        
    }
    else {
        search(container, subset, k+1, weight, answer);
        subset.push_back(container[k]);
        search(container, subset, k+1, weight, answer);
        subset.pop_back();
    }
}

void solve() {
    int numberOfApples { 0 };
    cin >> numberOfApples;
    vector<int> apples (numberOfApples);
    for (int i = 0; i < numberOfApples; i++) {
        cin >> apples[i];
    }
    vector<int> subset;
    int weight { reduce(apples.begin(), apples.end()) };
    int answer { weight };
    search(apples, subset, 0, weight, answer);
    cout << answer << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}