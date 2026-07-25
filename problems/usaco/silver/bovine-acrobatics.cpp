#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    int numberOfTowers { 0 };
    int difference { 0 };
    cin >> numberOfCows >> numberOfTowers >> difference;
    vector<pair<int, int>> cows (numberOfCows);
    for (auto& a : cows) {
        cin >> a.first >> a.second;
        a.second = min(a.second, numberOfTowers);
    }
    sort(cows.begin(), cows.end());
    reverse(cows.begin(), cows.end());
    deque<pair<int, int>> towers;
    towers.push_back({INT_MAX, numberOfTowers});
    int answer { 0 };
    for (int i = 0; i < numberOfCows; i++) {
        int temp { cows[i].second };
        while (!towers.empty() && towers[0].first >= cows[i].first + difference && temp > 0) {
            if (towers[0].second > temp) {
                towers[0].second -= temp;
                temp = 0;
                break;
            }
            else {
                temp -= towers[0].second;
                towers.pop_front();
            }
        }
        towers.push_back({cows[i].first, cows[i].second-temp});
        answer += cows[i].second-temp;
    }
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
