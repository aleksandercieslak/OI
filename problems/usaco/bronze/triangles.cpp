#include <bits/stdc++.h>
using namespace std;

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