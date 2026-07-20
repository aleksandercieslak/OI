#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    int maxTowers { 0 };
    int maxDiff { 0 };
    cin >> numberOfCows >> maxTowers >> maxDiff;
    vector<pair<int, int>> cows (numberOfCows);
    for (int i = 0; i < numberOfCows; i++) {
        cin >> cows[i].first >> cows[i].second;
        cows[i].second = min(cows[i].second, maxTowers);
    }
    sort(cows.begin(), cows.end());
    reverse(cows.begin(), cows.end());
    deque<pair<int, int>> towers;
    towers.push_back({INT_MAX, maxTowers});
    int counter { 0 };
    for (int i = 0; i < numberOfCows; i++) {
        int temp { cows[i].second };
        while (!towers.empty() && towers[0].first >= cows[i].first + maxDiff && temp > 0) {
            if (towers[0].second <= temp) {
                temp -= towers[0].second;
                towers.pop_front();
            }
            else {
                towers[0].second -= temp;
                temp = 0;
                break;
            }
        }
        towers.push_back({cows[i].first, cows[i].second - temp});
        counter += cows[i].second - temp;
    }
    cout << counter << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
