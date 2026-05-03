#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    cin >> numberOfCows;
    vector<int> indices (numberOfCows);
    vector<long long> prefix (numberOfCows);
    unordered_map<long long, int> positions;
    for (int i = 0; i < numberOfCows; i++) {
        cin >> indices[i];
        if (i == 0) { prefix[i] = indices[i]; }
        else {
            prefix[i] = prefix[i-1] + indices[i];
        }
        positions[prefix[i]] = i;
    }
    int answer { 0 };
    for (auto a : positions) {
        for (int i = 7; i <= a.first; i+=7) {
            long long needed { a.first-i };
            if (positions.count(needed) == 1) {
                answer = max(answer, a.second-positions[needed]+1);
                break;
            }
        }
    }
    cout << answer << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}