#include <bits/stdc++.h>
using namespace std;

void solve() {
    string point;
    vector<pair<char, char>> crossing;
    cin >> point;
    int firstPosition { 52 };
    int secondPosition { 0 };
    for (int i = 0; i < 52; i++) {
        for (int k = 0; k < 52; k++) {
            if (point[k] == point[i] && k > firstPosition) {
                secondPosition = k;
            }
            else if (point[k] == point[i]) {
                firstPosition = k;
            }
        }
        if (count(point.begin() + i, point.end(), point[i]) > 1) {
            for (int j = i + 1; j < 52; j++) {
                if (point[j] == point[i]) {
                    break;
                }
                if (count(point.begin() + firstPosition, point.begin() + secondPosition, point[j]) == 1) {
                    int one = min(point[j], point[i]);
                    int two = max(point[j], point[i]);
                    crossing.push_back({one, two});
                }
            }
        }
        firstPosition = 52;
        secondPosition = 0;
    }
    cout << crossing.size()/2 << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}