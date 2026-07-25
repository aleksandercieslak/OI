#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfOpponents { 0 };
    int time { 0 };
    cin >> numberOfOpponents >> time;
    vector<int> oppontents (numberOfOpponents);
    for (int& a : oppontents) {
        cin >> a;
    }
    vector<pair<int, int>> sorted (numberOfOpponents);
    for (int i = 0; i < numberOfOpponents; i++) {
        sorted[i].first = oppontents[i];
        sorted[i].second = i;
    }
    sort(sorted.begin(), sorted.end());
    int wins { 0 };
    vector<bool> beaten (numberOfOpponents);
    for (int i = 0; i < numberOfOpponents; i++) {
        if (time >= sorted[i].first) {
            if (i < numberOfOpponents-1 && time - sorted[i].first < sorted[i+1].first && time >= sorted[i+1].first) {
                int bestIndex { 0 };
                int bestPlacement { 0 };
                for (int j = i; j < numberOfOpponents; j++) {
                    if (sorted[j].second >= bestPlacement && time >= sorted[j].first) {
                        bestIndex = j;
                        bestPlacement = sorted[j].second;
                    }
                    if (time < sorted[j].first) {
                        beaten[bestIndex] = true;
                        wins++;
                        time -= sorted[bestIndex].first;
                        break;
                    }
                }
            }
            else {
                wins++;
                time -= sorted[i].first;
                beaten[i] = true;
            }
        }
        else {
            break;
        }
    }
    vector<int> victories (numberOfOpponents);
    for (int i = 0; i < numberOfOpponents; i++) {
        victories[i] += sorted[i].second;
        if (!beaten[i]) {
            victories[i]++;
        }
    }
    sort(victories.begin(), victories.end(), [](const int& a, const int& b) { return a > b;});
    int moreWins { 0 };
    for (const int& a : victories) {
        if (a > wins) {
            moreWins++;
        }
        else {
            break;
        }
    }
    cout << moreWins+1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests { 0 };
    cin >> tests;
    for (int q = 0; q < tests; q++) {
        solve();
    }
    return 0;
}
