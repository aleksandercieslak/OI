#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    cin >> numberOfCows;
    vector<int> bucketsInUse(1001);
    int largestAmount { 0 };
    for (int i = 0; i < numberOfCows; i++) {
        int startTime { 0 };
        int endTime { 0 };
        int buckets { 0 };
        cin >> startTime >> endTime >> buckets;
        for (int j = startTime; j < endTime + 1; j++) {
            bucketsInUse[j] += buckets;
            if (bucketsInUse[j] > largestAmount) {
                largestAmount = bucketsInUse[j];
            }
        }
    }
    cout << largestAmount << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}