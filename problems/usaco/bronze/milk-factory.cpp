#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> walkways;
vector<bool> isCompatible;

void search(unordered_set<int> checked, vector<int> current, int numberOfStations, int station) {
    if (static_cast<int>(checked.size()) == numberOfStations-1) {
        isCompatible[station] = true;
    }
    else {
        for (int a : current) {
            if (checked.count(a) == 0) {
                checked.insert(a);
                search(checked, walkways[a], numberOfStations, station);
            }
        }
    }
}

void solve() {
    int numberOfStations { 0 };
    cin >> numberOfStations;
    isCompatible.resize(numberOfStations+1);
    walkways.resize(numberOfStations+1);
    for (int i = 0; i < numberOfStations-1; i++) {
        int start, finish;
        cin >> start >> finish;
        walkways[finish].push_back(start);
    }
    for (int i = 1; i <= numberOfStations; i++) {
        if (walkways[i].empty()) { continue; }
        unordered_set<int> checked;
        vector<int> current = walkways[i];
        search(checked, current, numberOfStations, i); 
    }
    if (count(isCompatible.begin(), isCompatible.end(), true) == 0) { cout << -1 << "\n"; }
    else {
        for (int i = 1; i <= numberOfStations; i++) {
            if (isCompatible[i]) {
                cout << i << "\n";
                break;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}