#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    cin >> numberOfCows;
    vector<int> cows (numberOfCows);
    for (int& a : cows) {
        cin >> a;
    }
    sort(cows.begin(), cows.end(), [](const int& a, const int& b) { return a > b; });
    int lineLength { 0 };
    for (int i = 0; i < numberOfCows; i++) {
        if (cows[i] >= lineLength) {
            lineLength++;
        }
        else {
            break;
        }
    }
    cout << lineLength << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
