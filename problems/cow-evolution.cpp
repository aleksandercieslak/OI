#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfSubPopulations { 0 };
    cin >> numberOfSubPopulations;
    vector<vector<string>> populations (numberOfSubPopulations);
    unordered_set<string> abilities;
    for (int i = 0; i < numberOfSubPopulations; i++) {
        int number;
        cin >> number;
        for (int j = 0; j < number; j++) {
            string ability;
            cin >> ability;
            abilities.insert(ability);
            populations[i].push_back(ability);
        }
    }
    int numberOfAbilities = static_cast<int>(abilities.size());
    bool isProper = true;
    vector<string> abilitiesVector (abilities.begin(), abilities.end());
    for (int a = 0; a < numberOfAbilities-1; a++) {
        for (int b = a+1; b < numberOfAbilities; b++) {
            string firstAbility = abilitiesVector[a];
            string secondAbility = abilitiesVector[b];
            bool onlyFirst { false };
            bool onlySecond { false };
            bool both { false };
            for (int i = 0; i < numberOfSubPopulations; i++) {
                bool hasFirst = count(populations[i].begin(), populations[i].end(), abilitiesVector[a]);
                bool hasSecond = count(populations[i].begin(), populations[i].end(), abilitiesVector[b]);
                if (hasFirst && !hasSecond) { onlyFirst = true; }
                if (!hasFirst && hasSecond) { onlySecond = true; }
                if (hasFirst && hasSecond) { both = true; }
            }
            if (onlyFirst && onlySecond && both) { isProper = false; }
        }
    }
    if (isProper) { cout << "yes" << "\n"; }
    else { cout << "no" << "\n"; }
}

int main() {
    cin.tie(0);
    solve();
}