#include <bits/stdc++.h>
using namespace std;

void solve() {
    int small { 0 };
    int medium { 0 };
    int big { 0 };
    int milk { 0 };
    int maximum { 0 };
    cin >> small >> medium >> big;
    for (int first = 0; first <= big; first++) {
        if (first*small > big) { break; }
        for (int second = 0; second <= big; second++) {
            milk = first*small + second*medium;
            if (milk > big) { break; }
            maximum = max(maximum, milk);
        }
    }
    cout << maximum << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}