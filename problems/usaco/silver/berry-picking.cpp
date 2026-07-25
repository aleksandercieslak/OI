#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfTrees { 0 };
    int numberOfBaskets { 0 };
    cin >> numberOfTrees >> numberOfBaskets;
    deque<int> trees (numberOfTrees);
    for (int& a : trees) {
        cin >> a;
    }
    sort(trees.begin(), trees.end());
    while (static_cast<int>(trees.size()) > numberOfBaskets) {
        trees.pop_front();
    }
    int minBerries { trees[0] };
    int maxBerries { trees[numberOfBaskets-1] };
    int answer { 0 };
    for (int berries = minBerries; berries < maxBerries; berries++) {
        int counter { 0 };
        deque<int> temp;
        for (const int& a : trees) {
            if (a%berries != 0) {
                if (a > berries) {
                    temp.push_back(a%berries+berries);
                    counter += a/berries-1;
                }
                else {
                    temp.push_back(a);
                }
            }
            else {
                counter += a/berries;
            }
        }
        if (static_cast<int>(temp.size())+counter < numberOfBaskets) { continue; }
        int index { 0 };
        int i { static_cast<int>(temp.size())-1 };
        int total { 0 };
        while (index < numberOfBaskets) {
            if (index < numberOfBaskets/2) {
               if (temp[i] > berries || counter <= 0) {
                   i--;
               } 
               else {
                   counter--;
               }
            }
            else {
                if (i >= 0 && (temp[i] > berries || counter <= 0)) {
                    total += temp[i];
                    i--;
                }
                else {
                    total += berries;
                    counter--;
                }
            }
            index++;
        }
        answer = max(answer, total);
    }
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
