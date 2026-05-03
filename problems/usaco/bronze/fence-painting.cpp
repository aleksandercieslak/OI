#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<bool> fence (101);
    for (int i = a; i < b; i++) {
        fence[i] = true;
    }
    for (int i = c; i < d; i++) {
        fence[i] = true;
    }
    cout << count(fence.begin(), fence.end(), true) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}