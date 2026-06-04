#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    cin >> numberOfCows;
    vector<int> order (numberOfCows);
    vector<int> expected (numberOfCows);
    for (int i = 0; i < numberOfCows; i++) {
        cin >> order[i];
    }
    for (int i = 0; i < numberOfCows; i++) {
        cin >> expected[i];
    }
    unordered_map<int, vector<int>> distances;
    for (int i = 0; i < numberOfCows; i++) {
        if (distances.count(expected[i]) == 0) {
            vector<int> temp;
            distances[expected[i]] = temp;
        }
        distances[expected[i]].push_back(min(i+1, numberOfCows-i));
    }
    unordered_map<int, vector<int>> prefix;
    for (auto &a : distances) {
        sort(a.second.begin(), a.second.end());
        vector<int> temp = {0};
        for (int b : a.second) {
            temp.push_back(b+temp.back());
        }
        prefix[a.first] = temp;
    }
    long long answer { 0 };
    for (int i = 0; i < numberOfCows; i++) {
        int species { order[i] };
        if (distances.count(species) == 0) { continue; }
        int distanceToEdge { min(i+1, numberOfCows-i) };
        int index { static_cast<int>(upper_bound(distances[species].begin(), distances[species].end(), distanceToEdge) - distances[species].begin()) };
        answer += prefix[species][index];
        answer += (distances[species].size()-index) * distanceToEdge;

        if (order[i] == expected[i]) {
            answer += i*(i+1)/2 + (numberOfCows-i)*(numberOfCows-i-1)/2;
        }
    }
    cout << answer << "\n"; 
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}