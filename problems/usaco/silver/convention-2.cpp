#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    cin >> numberOfCows;
    vector<pair<int, int>> temp (numberOfCows);
    for (auto& a : temp) {
        cin >> a.first >> a.second;
    }
    deque<pair<int, pair<int, int>>> cows (numberOfCows);
    for (int i = 0; i < numberOfCows; i++) {
        cows[i].first = i;
        cows[i].second.first = temp[i].first;
        cows[i].second.second = temp[i].second;
    }
    sort(cows.begin(), cows.end(), [](const auto& a, const auto& b) {
        if (a.second.first == b.second.first) {
            return a.first < a.first;
        }
        return a.second.first < b.second.first;
    });
    int current { 0 };
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> lobby;
    int answer { 0 };
    while (!lobby.empty() || !cows.empty()) {
        while (!cows.empty() && cows[0].second.first <= current) {
            lobby.push({cows[0].first, {cows[0].second.first, cows[0].second.second}}); 
            cows.pop_front();
        }
        if (lobby.empty()) {
            current = cows[0].second.first + cows[0].second.second; 
            cows.pop_front();
        }
        else {
            answer = max(answer, current-lobby.top().second.first);
            current += lobby.top().second.second; 
            lobby.pop();
        }
    }
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
