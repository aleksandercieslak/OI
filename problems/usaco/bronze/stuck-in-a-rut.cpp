#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    cin >> numberOfCows;
    struct Info {
        char direction;
        int x;
        int y;
        int numberOfSteps;
    };
    vector<Info> cow(numberOfCows);
    vector<tuple<int, int, int>> steps;
    for (int i = 0; i < numberOfCows; i++) {
        cin >> cow[i].direction >> cow[i].x >> cow[i].y;
    }
    for (int i = 0; i < numberOfCows; i++) {
        for (int j = 0; j < numberOfCows; j++) {
            if (cow[i].direction != cow[j].direction) {
                if (cow[i].direction == 'N') { 
                    if (cow[i].y < cow[j].y && cow[i].x > cow[j].x) {
                         if (abs(cow[j].x - cow[i].x) < abs(cow[i].y - cow[j].y)) {
                            steps.push_back({cow[j].y - cow[i].y, i, j});
                        }
                    }
                }
                else if (cow[i].direction == 'E') {
                    if (cow[i].x < cow[j].x && cow[i].y > cow[j].y) {
                        if (abs(cow[j].x - cow[i].x) > abs(cow[i].y - cow[j].y)) {
                            steps.push_back({cow[j].x - cow[i].x, i, j});
                        }
                    }
                }
            }
            else if (cow[i].direction == cow[j].direction) {
                if (cow[i].direction == 'N') {
                    if (cow[i].x == cow[j].x && cow[i].y < cow[j].y) {
                        steps.push_back({cow[j].y - cow[i].y, i, j});
                    }
                }
                if (cow[i].direction == 'E') {
                    if (cow[i].y == cow[j].y && cow[i].x < cow[j].x) {
                        steps.push_back({cow[j].x - cow[i].x, i, j});
                    }
                }
            }
        }
    }
    sort(steps.begin(), steps.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) { return get<0>(a) < get<0>(b); });
    vector<int> stuckCows;
    vector<int> answers (numberOfCows);
    for (const auto& a : steps) {
        if (count(stuckCows.begin(), stuckCows.end(), get<2>(a)) == 0 && count(stuckCows.begin(), stuckCows.end(), get<1>(a)) == 0) {
            answers[get<1>(a)] = get<0>(a);
            stuckCows.push_back(get<1>(a));
        }
    }
    for (const auto& a : answers) {
        if (a == 0) {
            cout << "Infinity\n";
        }
        else {
            cout << a <<"\n";
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}