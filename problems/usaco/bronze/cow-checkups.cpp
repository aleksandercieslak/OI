#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    int matchCounter { 0 };
    int validCombinations { 0 };
    cin >> numberOfCows;
    vector<int> cowSpecies (numberOfCows);
    vector<int> requiredSpecies (numberOfCows);
    for (int i = 0; i < numberOfCows; i++) {
        cin >> cowSpecies[i];
    }
    for (int i = 0; i < numberOfCows; i++) {
        cin >> requiredSpecies[i];
    }
    for (int i = 0; i < numberOfCows+1; i++) {
        for (int j = 0; j < numberOfCows; j++) {
            for (int k = 0; k < numberOfCows; k++) {
                if (j <= k) {
                    vector<int> temp = cowSpecies;
                    reverse(temp.begin() + j, temp.begin() + k + 1);
                    for (int l = 0; l < numberOfCows; l++) {
                        if (temp[l] == requiredSpecies[l]) {
                            matchCounter++;
                        }
                    }
                    if (matchCounter == i) {
                        validCombinations++;
                    }
                    matchCounter = 0;
                }
            }
        }
        cout << validCombinations << "\n";
        validCombinations = 0;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}