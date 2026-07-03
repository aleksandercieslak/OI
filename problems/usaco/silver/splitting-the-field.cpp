#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    cin >> numberOfCows;
    vector<pair<int, int>> cows (numberOfCows);
    for (int i = 0; i < numberOfCows; i++) {
        cin >> cows[i].first >> cows[i].second;
    }
    int baseArea { 0 };
    int left { 1000000000 };
    int right { 0 };
    int bottom { 1000000000 };
    int top { 0 };
    for (int i = 0; i < numberOfCows; i++) {
        left = min(cows[i].first, left);
        right = max(cows[i].first, right);
        bottom = min(cows[i].second, bottom);
        top = max(cows[i].second, top);
    }
    baseArea = (right-left)*(top-bottom);
    sort(cows.begin(), cows.end(), [](pair<int, int> a, pair<int, int> b) { return a.first < b.first; });
    int maxHorizontalGap { 0 };
    int horizontalGapIndex { 0 };
    for (int i = 1; i < numberOfCows; i++) {
        if (cows[i].first-cows[i-1].first+abs(cows[i].second-cows[i-1].second) > maxHorizontalGap) {
            maxHorizontalGap = cows[i].first-cows[i-1].first+abs(cows[i].second-cows[i-1].second);
            horizontalGapIndex = i;
        }
    }
    sort(cows.begin(), cows.end(), [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
    int maxVerticalGap { 0 };
    int verticalGapIndex { 0 };
    for (int i = 1; i < numberOfCows; i++) {
        if (cows[i].second-cows[i-1].second+abs(cows[i].first-cows[i-1].first) > maxVerticalGap) {
            maxVerticalGap = cows[i].second-cows[i-1].second+abs(cows[i].first-cows[i-1].first);
            verticalGapIndex = i;
        }
    }
    int l1 { 1000000000 };
    int r1 { 0 };
    int b1 { 1000000000 };
    int t1 { 0 };
    int l2 { 1000000000 };
    int r2 { 0 };
    int b2 { 1000000000 };
    int t2 { 0 };
    if (maxHorizontalGap > maxVerticalGap) {
        sort(cows.begin(), cows.end(), [](pair<int, int> a, pair<int, int> b) { return a.first < b.first; });
        for (int i = 0; i < horizontalGapIndex; i++) {
            l1 = min(l1, cows[i].first);
            r1 = max(r1, cows[i].first);
            b1 = min(b1, cows[i].second);
            t1 = max(t1, cows[i].second);
        }
        for (int i = horizontalGapIndex; i < numberOfCows; i++) {
            l2 = min(l2, cows[i].first);
            r2 = max(r2, cows[i].first);
            b2 = min(b2, cows[i].second);
            t2 = max(t2, cows[i].second);
        }
    }
    else {
        sort(cows.begin(), cows.end(), [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
        for (int i = 0; i < verticalGapIndex; i++) {
            l1 = min(l1, cows[i].first);
            r1 = max(r1, cows[i].first);
            b1 = min(b1, cows[i].second);
            t1 = max(t1, cows[i].second);
        }
        for (int i = verticalGapIndex; i < numberOfCows; i++) {
            l2 = min(l2, cows[i].first);
            r2 = max(r2, cows[i].first);
            b2 = min(b2, cows[i].second);
            t2 = max(t2, cows[i].second);
        }
    }
    int newArea { (r1-l1)*(t1-b1) + (r2-l2)*(t2-b2) };
    cout << baseArea-newArea << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}