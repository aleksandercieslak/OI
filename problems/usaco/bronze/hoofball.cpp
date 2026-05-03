#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    cin >> numberOfCows;
    vector<int> cows (numberOfCows);
    for (int i = 0; i < numberOfCows; i++) {
        cin >> cows[i];
    }
    if (numberOfCows == 1) { cout << 1 << "\n"; }
    else if (numberOfCows > 1) {
        sort(cows.begin(), cows.end());
        vector<vector<int>> cowsPassingTo (numberOfCows);
        vector<int> cowPassedBy (numberOfCows);
        cowsPassingTo[1].push_back(0);
        cowsPassingTo[numberOfCows-2].push_back(numberOfCows-1);
        cowPassedBy[0] = 1;
        cowPassedBy[numberOfCows-1] = numberOfCows-2;
        for (int i = 1; i < numberOfCows-1; i++) {
            if (cows[i]-cows[i-1] <= cows[i+1]-cows[i]) {
                cowsPassingTo[i-1].push_back(i);
                cowPassedBy[i] = i-1;
            }
            else if (cows[i]-cows[i-1] > cows[i+1]-cows[i]) {
                cowsPassingTo[i+1].push_back(i);
                cowPassedBy[i] = i+1;
            }
        }
        int balls { 0 };
        int temp { 0 };
        for (int i = 0; i < numberOfCows; i++) {
            if (cowsPassingTo[i].empty()) { balls++; }
            if (cowPassedBy[cowPassedBy[i]] == i && cowsPassingTo[i].size() == 1 && cowsPassingTo[cowPassedBy[i]].size() == 1) {
                temp++;
            }
        }
        cout << balls + temp/2 << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}