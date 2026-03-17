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
    int numberOfPosts { 0 };
    cin >> numberOfPosts;
    vector<pair<int, int>> posts (numberOfPosts);
    for (int i = 0; i < numberOfPosts; i++) {
        cin >> posts[i].first >> posts[i].second;
    }
    int maxArea { 0 };
    for (int i = 0; i < numberOfPosts; i++) {
        for (int j = 0; j < numberOfPosts; j++) {
            for (int k = 0; k < numberOfPosts; k++) {
                if (posts[i].second == posts[j].second && posts[i].first == posts[k].first) {
                    maxArea = max(maxArea, abs(posts[j].first - posts[i].first) * abs(posts[k].second - posts[i].second));
                }
            }
        }
    }
    cout << maxArea << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}