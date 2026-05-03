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
    string magazine;
    string phrase;
    cin >> magazine >> phrase;
    while (magazine.find(phrase) != string::npos) {
        magazine.erase(magazine.find(phrase), phrase.length());
    }
    cout << magazine << "\n";   
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}