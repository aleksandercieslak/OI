#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfHay { 0 };
    cin >> numberOfHay;
    vector<int> hayBales (numberOfHay);
    for (int i = 0; i < numberOfHay; i++) {
        cin >> hayBales[i];
    }
    sort(hayBales.begin(), hayBales.end());
    int bestScore { 0 };
    for (int i = 0; i < numberOfHay; i++) {
        vector<int> newHay = hayBales;
        bool exploding { true };
        int time { 0 };
        int counter { 1 };
        vector<int> indices {i};
        while (exploding) {
            time++;
            int indicesLength { static_cast<int>(indices.size()) };
            vector<int> newIndices;
            int succesfulExplosions { 0 }; 
            for (int j = 0; j < indicesLength; j++) {
                for (int k = 1; k <= time; k++) {
                    if (indices[j]-k >= 0 && newHay[indices[j]-k] != 0) {
                        if (newHay[indices[j]]-newHay[indices[j]-k] <= time) {
                            newIndices.push_back(indices[j]-k);
                            counter++;
                            succesfulExplosions++;
                            newHay[indices[j]-k] = 0;
                        }
                    }
                    if (indices[j]+k < static_cast<int>(newHay.size()) && newHay[indices[j]+k] != 0) {
                        if (newHay[indices[j]+k]-newHay[indices[j]] <= time) {
                            newIndices.push_back(indices[j]+k);
                            counter++;
                            succesfulExplosions++;
                            newHay[indices[j]+k] = 0;
                        }
                    }
                }
            }
            if (succesfulExplosions == 0) {
                exploding = false;
                bestScore = max(bestScore, counter);
            }
            indices = newIndices;
        }
    }
    cout << bestScore << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}