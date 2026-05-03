#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfFlowers { 0 };
    cin >> numberOfFlowers;
    vector<int> petals (numberOfFlowers);
    for (int i = 0; i < numberOfFlowers; i++) {
        cin >> petals[i];
    }
    int answer { 0 };
    for (int i = 0; i < numberOfFlowers; i++) {
        for (int j = i; j < numberOfFlowers; j++) {
        int sum = reduce(petals.begin() + i, petals.begin() + j);
        int average = sum/(j-i);       
            if (count(petals.begin() + i, petals.begin() + j, average) > 0) {
                answer++;
            }
        }
    }
    cout << answer << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}