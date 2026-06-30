#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    cin >> numberOfCows;
    vector<pair<int, int>> cows (numberOfCows);
    for (int i = 0; i < numberOfCows; i++) {
        cin >> cows[i].first >> cows[i].second;
    }
    sort(cows.begin(), cows.end());
    int index { 1 };
    for (int i = 0; i < numberOfCows; i++) {
        cows[i].first = index;
        index++;
    }
    sort(cows.begin(), cows.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
    index = 1;
    for (int i = 0; i < numberOfCows; i++) {
        cows[i].second = index;
        index++;
    }
    vector<vector<int>> position (numberOfCows+1, vector<int>(numberOfCows+1));
    vector<vector<int>> prefix (numberOfCows+1, vector<int>(numberOfCows+1));
    for (auto a : cows) {
        position[a.first][a.second] = 1;
    }
    for (int i = 1; i <= numberOfCows; i++) {
        for (int j = 1; j <= numberOfCows; j++) {
            prefix[i][j] = position[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
    long long answer { 0 };
    for (int i = 0; i < numberOfCows; i++) {
        for (int j = i; j < numberOfCows; j++) {
            int x1 { min(cows[i].first, cows[j].first)-1 };
            int x2 { max(cows[i].first, cows[j].first)-1 };
            int y1 { i };
            int y2 { j };
            int rec1 { prefix[x1+1][y2+1] - prefix[0][y2+1] - prefix[x1+1][y1] + prefix[0][y1] };
            int rec2 { prefix[numberOfCows-1+1][y2+1] - prefix[x2][y2+1] - prefix[numberOfCows-1+1][y1] + prefix[x2][y1] };
            answer += rec1 * rec2;
        }
    }
    answer++;
    cout << answer << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}