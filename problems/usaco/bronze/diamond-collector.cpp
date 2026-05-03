#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfDiamonds { 0 };
    int difference { 0 };
    int amountOfDiamonds { 0 };
    cin >> numberOfDiamonds >> difference;
    vector<int> diamond (numberOfDiamonds);
    for (int i = 0; i < numberOfDiamonds; i++) {
        cin >> diamond[i];
    }
    sort(diamond.begin(), diamond.end(), [](int x, int y) { return x < y; });
    for (int i = 0; i < numberOfDiamonds-1; i += 2) {
        if (diamond[i] != diamond.back()) {
            if (diamond[i] - diamond[i+1] <= difference) {
                amountOfDiamonds += 2;
            } 
        }
    }
    cout << amountOfDiamonds << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}