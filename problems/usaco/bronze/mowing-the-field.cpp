#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfMoves { 0 };
    int time { 1 };
    int timeConstant { 1 };
    vector<int> intersectionTimes;
    vector<pair<int, int>> position ( 10000 );
    position[0] = {0, 0};
    cin >> numberOfMoves;
    vector<pair<char, int>> moves (numberOfMoves);
    for (int i = 0; i < numberOfMoves; i++) {
        cin >> moves[i].first >> moves[i].second;
    }
    for (int i = 0; i < numberOfMoves; i++) {
        timeConstant = time;
        if (moves[i].first == 'N') {
            for (int j = time; j < timeConstant+moves[i].second; j++) {
                position[j] = position[j-1];
                position[j].second++;
                time++;
            }
        }
        else if (moves[i].first == 'S') {
            for (int j = time; j < timeConstant+moves[i].second; j++) {
                position[j] = position[j-1];
                position[j].second--;
                time++;
            }
        }
        else if (moves[i].first == 'E') {
            for (int j = time; j < timeConstant+moves[i].second; j++) {
                position[j] = position[j-1];
                position[j].first++;
                time++;
            }
        }
        else if (moves[i].first == 'W') {
            for (int j = time; j < timeConstant+moves[i].second; j++) {
                position[j] = position[j-1];
                position[j].first--;
                time++;
            }
        }
    }
    for (int i = 0; i < time; i++) {
        for (int j = 0; j < time; j++) {
            if (position[i].first == position[j].first && position[i].second == position[j].second && i != j) {
                intersectionTimes.push_back(abs(i-j));
            }
        }
    }

    cout << *min_element(intersectionTimes.begin(), intersectionTimes.end()) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}