#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> haybales) {
    int left { 0 };
    int right { 0 };
    cin >> left >> right;
    auto ptrLeft { lower_bound(haybales.begin(), haybales.end(), left) };
    auto ptrRight { upper_bound(haybales.begin(), haybales.end(), right) };
    cout << ptrRight-ptrLeft << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int numberOfHaybales { 0 };
    int numberOfQueries { 0 };
    cin >> numberOfHaybales >> numberOfQueries;
    vector<int> haybales (numberOfHaybales);
    for (int i = 0; i < numberOfHaybales; i++) {
        cin >> haybales[i];
    }
    sort(haybales.begin(), haybales.end());
    for (int q = 0; q < numberOfQueries; q++) {
        solve(haybales);
    }
}