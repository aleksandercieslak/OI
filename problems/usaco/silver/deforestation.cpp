#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfTrees { 0 };
    int numberOfLaws { 0 };
    cin >> numberOfTrees >> numberOfLaws;
    vector<int> trees (numberOfTrees);
    for (int& a : trees) {
        cin >> a;
    }
    sort(trees.begin(), trees.end());
    vector<array<int, 4>> spots;
    for (int i = 0; i < numberOfLaws; i++) {
        int l, r, t;
        cin >> l >> r >> t;
        auto itLeft { lower_bound(trees.begin(), trees.end(), l) };
        auto itRight { upper_bound(trees.begin(), trees.end(), r) };
        spots.push_back({l, r, static_cast<int>(itRight-itLeft)-t, 0});
    }
    for (const int& a : trees) {
        spots.push_back({a, 0, 0, 1});
    }
    sort(spots.begin(), spots.end(), [](const auto& a, const auto& b) {
        if (a[0] != b[0] || a[3] == 0) {
            return a < b;
        }
        else {
            return b < a; 
        }
    });
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int answer { 0 }; 
    for (auto& a : spots) {
        if (a[3] == 0) {
            pq.push({answer+a[2], a[1]});
        }
        else {
            while (!pq.empty() && pq.top().second < a[0]) {
               pq.pop(); 
            }
            if (pq.empty() || answer != pq.top().first) {
                answer++;
            }
        }
    }
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests { 0 };
    cin >> tests;
    for (int i = 0; i < tests; i++) {
        solve();
    }
    return 0;
}
