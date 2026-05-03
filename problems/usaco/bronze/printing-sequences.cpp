#include <bits/stdc++.h>
using namespace std;

int numberOfTests { 0 };

void solve() {
    cin >> numberOfTests;
    for (int i = 0; i < numberOfTests; i++) {
        int maxNumber { 0 };
        int sLength { 0 };
        string answer;
        cin >> sLength >> maxNumber;
        vector<int> sequence (sLength);
        for (int i = 0; i < sLength; i++) {
            cin >> sequence[i];
        }
        int sSum { reduce(sequence.begin(), sequence.end()) };
        if (sSum == sLength || sSum == 2*sLength || sSum == 3*sLength) { answer == "YES"; }
        else {
            vector<int> divisors;
            vector<int> divided;
            int dLength { 0 };
            for (int i = 1; i <= sLength; i++) {
                if (sLength%i == 0) {
                    divisors.push_back(i);
                    divided.push_back(sLength/i);
                    dLength++;
                }
            }
            
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}