#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfPatches { 0 };
    int numberOfNhojCows { 0 };
    int numberOfCows { 0 };
    cin >> numberOfPatches >> numberOfNhojCows >> numberOfCows;
    vector<pair<int, int>> spots;
    long long maxTastiness { 0 };
    for (int i = 0; i < numberOfPatches; i++) {
        int p;
        int t;
        cin >> p >> t;
        maxTastiness += t;
        spots.push_back({p, t});
    }
    for (int i = 0; i < numberOfNhojCows; i++) {
        int f;
        cin >> f;
        spots.push_back({f, -1});
    }
    sort(spots.begin(), spots.end());
    int total { numberOfPatches+numberOfNhojCows }; 
    int lastCow { -1 };
    vector<long long> tastiness;
    for (int i = 0; i < total; i++) {
        if (spots[i].second == -1) {
            if (lastCow == -1) {
                long long currentSum { 0 };
                for (int j = 0; j < i; j++) {
                    currentSum += spots[j].second;
                }
                tastiness.push_back(currentSum);
            }
            else {
                long long radius { (spots[i].first-spots[lastCow].first) };
                long long counter { 0 };
                int k { lastCow+1 };
                long long segment { 0 };
                long long best { 0 };
                for (int j = lastCow+1; j < i; j++) {
                    counter += spots[j].second;
                    segment += spots[j].second;
                    while (static_cast<long long>(spots[j].first - spots[k].first)*2 >= radius) {
                        counter -= spots[k].second;
                        k++;
                    }
                    best = max(best, counter);
                }
                tastiness.push_back(best);
                tastiness.push_back(segment-best);
            }
            lastCow = i;
        }
    }
    long long count { 0 }; 
    for (int i = total-1; i >= 0; i--) {
        if (spots[i].second == -1) {
            tastiness.push_back(count);
            break;
        }
        else {
            count += spots[i].second;
        }
    }
    long long answer { 0 };
    sort(tastiness.begin(), tastiness.end());
    reverse(tastiness.begin(), tastiness.end());
    for (int i = 0; i < min(numberOfCows, static_cast<int>(tastiness.size())); i++) {
        answer += tastiness[i]; 
    }
    if (numberOfNhojCows == 0) {
        cout << maxTastiness << "\n";
    }
    else {
        cout << answer << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
