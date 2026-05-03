#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    cin >> numberOfCows;
    int liars { 0 };
    int firstIndex { 0 };
    long long secondIndex { 1000000000 };
    vector<pair<char, int>> cow (numberOfCows);
    for (int i = 0; i < numberOfCows; i++) {
        cin >> cow[i].first >> cow[i].second;
    }
    for (int i = 0; i < numberOfCows; i++) {
        if (cow[i].first == 'L' && cow[i].second <= firstIndex) {
            liars++;
        }
        else if (cow[i].first == 'G' && cow[i].second >= secondIndex) {
            liars++;
        }
        else if (cow[i].first == 'L' && cow[i].second > firstIndex) {
            secondIndex = cow[i].second;
        }
        else if (cow[i].first == 'G' && cow[i].second < secondIndex) {
            firstIndex = cow[i].second;
        }
    }
    cout << liars << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}