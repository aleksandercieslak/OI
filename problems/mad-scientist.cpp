#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    string goal;
    string order;
    cin >> numberOfCows >> goal >> order;
    int updates { 0 };
    for (int i = 0; i < numberOfCows; i++) {
        if (order[i] != goal[i]) {
            updates++;
            while (order[i+1] != goal[i+1]) {
                i++;
            }
        }
    }
    cout << updates << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}