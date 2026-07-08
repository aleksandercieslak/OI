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
    int newIndex { 1 };
    for (int i = 0; i < numberOfCows; i++) {
        cows[i].first = newIndex;
        newIndex++;
    }
    sort(cows.begin(), cows.end(), [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
    newIndex = 1;
    for (int i = 0; i < numberOfCows; i++) {
        cows[i].second = newIndex;
        newIndex++;
    }
    vector<vector<int>> field (numberOfCows+1, vector<int>(numberOfCows+1));
    for (int i = 0; i < numberOfCows; i++) {
        field[cows[i].first][cows[i].second] = 1;
    }
    vector<vector<int>> prefix (numberOfCows+1, vector<int>(numberOfCows+1));
    for (int i = 1; i <= numberOfCows; i++) {
        for (int j = 1; j <= numberOfCows; j++) {
            prefix[i][j] = field[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
    long long answer { 1 };
    for (int i = 0; i < numberOfCows; i++) {
        for (int j = i; j < numberOfCows; j++) {
            int left { min(cows[i].first, cows[j].first) };
            int right { max(cows[i].first, cows[j].first) };
            int bottom { min(cows[i].second, cows[j].second) };
            int top { max(cows[i].second, cows[j].second) };
            int leftPrefix { prefix[left-1][top] - prefix[left-1][bottom-1] };
            leftPrefix += 1;
            int rightPrefix { prefix[numberOfCows][top] - prefix[right][top] - prefix[numberOfCows][bottom-1] + prefix[right][bottom-1] };
            rightPrefix += 1;
            answer += rightPrefix*leftPrefix;
        }
    }
    cout << answer << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}