#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfPeaks { 0 };
    cin >> numberOfPeaks;
    vector<pair<int, int>> peaks (numberOfPeaks);
    for (int i = 0; i < numberOfPeaks; i++) {
        cin >> peaks[i].first >> peaks[i].second;
    }
    vector<pair<double, double>> ranges (numberOfPeaks);
    for (int i = 0; i < numberOfPeaks; i++) {
        double delta { sqrt(2)*static_cast<double>(peaks[i].second) };
        ranges[i].first = static_cast<double>(peaks[i].first) - delta;
        ranges[i].second = static_cast<double>(peaks[i].first) + delta;
    }
    struct Info {
        double left;
        double right;
        int peakX;
        int peakY;
    };
    vector<Info> mountains (numberOfPeaks);
    for (int i = 0; i < numberOfPeaks; i++) {
        mountains[i].left = ranges[i].first;
        mountains[i].right = ranges[i].second;
        mountains[i].peakX = peaks[i].first;
        mountains[i].peakY = peaks[i].second;
    }
    sort(mountains.begin(), mountains.end(), [](Info a, Info b) { return a.left < b.left; });
    Info last = mountains[0];
    int answer { 1 };
    for (int i = 1; i < numberOfPeaks; i++) {
        if (mountains[i].peakY > last.peakY || static_cast<double>(mountains[i].peakX) > last.right || static_cast<double>(mountains[i].peakY) > last.right - static_cast<double>(mountains[i].peakX)) {
            answer++;
        }
        if (mountains[i].right > last.right) {
            last = mountains[i];
        } 
    }
    cout << answer << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}