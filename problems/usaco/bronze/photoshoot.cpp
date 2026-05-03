#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    string cows;
    cin >> numberOfCows >> cows;
    int reversals { 0 };
    for (int i = numberOfCows - 2; i >= 0; i -= 2) {
        string temp = cows.substr(i, 2);
        if (temp[0] == temp[1]) { continue; }
        else if ((temp == "HG" && reversals%2 == 1) || (temp == "GH" && reversals%2 == 0)) {
            reversals++;
        }
    }
    cout << reversals << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}