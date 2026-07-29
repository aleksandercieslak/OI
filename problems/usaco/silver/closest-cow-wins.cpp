#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfPatches { 0 };
    int numberOfNhojCows { 0 };
    int numberOfCows { 0 };
    cin >> numberOfPatches >> numberOfNhojCows >> numberOfCows;
    vector<pair<int, int>> spots;
    for (int i = 0; i < numberOfPatches; i++) {
        int a, b;
        cin >> a >> b;
        spots.push_back({a, b});
    }
    for (int i = 0; i < numberOfNhojCows; i++) {
        int a;
        cin >> a;
        spots.push_back({a, -1});
    }
    sort(spots.begin(), spots.end());
    int size { numberOfNhojCows+numberOfPatches };
    vector<long long> score;
    int left { 0 };
    int right { 1 };
    long long between { 0 };
    long long temp { 0 };
    for (int i = 0; i < size; i++) {
        if (spots[i].second == -1) {
            left = i;
            right = i+1;
            score.push_back(temp);
            break;
        }
        temp += spots[i].second;
    }
    while (left < size-1 && right <= size-1) {
        if (spots[right].second != -1) {
            between += spots[right].second;
            right++;
        }
        else {
            int radius { spots[right].first - spots[left].first };
            int l { left+1 };
            long long value { 0 };
            long long cur { 0 };
            for (int r = left+1; r < right; r++) {
                cur += spots[r].second;
                while ((spots[r].first - spots[l].first)*2 >= radius) {
                    cur -= spots[l].second;
                    l++;
                }
                value = max(value, cur);
            }
            score.push_back(value);
            score.push_back(between-value);
            between = 0;
            left = right;
            right++;
        }
    }
    temp = 0;
    for (int i = left+1; i < size; i++) {
        temp += spots[i].second;
    }
    score.push_back(temp);
    sort(score.begin(), score.end());
    long long answer { 0 };
    for (int i = 0; i < min(numberOfCows, static_cast<int>(score.size())); i++) {
        answer += score.back();
        cout << score.back() << "\n";
        score.pop_back();
    }
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
