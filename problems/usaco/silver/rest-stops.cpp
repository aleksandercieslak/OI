#include <bits/stdc++.h>
using namespace std;

void solve() {
    int trailLength { 0 };
    int numberOfStops { 0 };
    int farmerPace { 0 };
    int bessiePace { 0 };
    cin >> trailLength >> numberOfStops >> farmerPace >> bessiePace;
    vector<pair<int, int>> stops (numberOfStops);
    for (auto& a : stops) {
        cin >> a.first >> a.second;
    }
    sort(stops.begin(), stops.end());
    vector<int> prefix (numberOfStops);
    prefix[numberOfStops-1] = numberOfStops-1;
    for (int i = numberOfStops-2; i >= 0; i--) {
        if (stops[i].second > stops[prefix[i+1]].second) {
            prefix[i] = i;
        }
        else {
            prefix[i] = prefix[i+1];
        }
    }
    int answer { 0 };
    int index { 0 };
    int last { 0 };
    while (index < numberOfStops) {
        index = prefix[index];
        int distance { stops[index].first - last };
        int time { farmerPace*distance - bessiePace*distance };
        answer += stops[index].second * time;
        last = stops[index].first;
        index++;
    }
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
