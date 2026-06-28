#include <bits/stdc++.h>
using namespace std;

bool valid(int highwayLength, vector<pair<int, int>> stations, double radius) {
    vector<pair<double, double>> indices;
    for (auto a : stations) {
        double distance { pow(pow(radius, 2) - pow(static_cast<double>(a.second), 2), 0.5) };
        indices.push_back({static_cast<double>(a.first)-distance, static_cast<double>(a.first)+distance});
    } 
    sort(indices.begin(), indices.end(), [](pair<double, double> a, pair<double, double> b) { return a.first < b.first; });
    if (indices[0].first > 0) { return false; }
    int l { static_cast<int>(indices.size()) };
    if (indices[l-1].second < highwayLength) { return false; }
    for (int i = 1; i < l; i++) {
        if (indices[i].first > indices[i-1].second) {
            return false;
        }
    }
    return true;
}

void solve() {
    int numberOfStations { 0 };
    int highwayLength { 0 };
    cin >> numberOfStations >> highwayLength;
    vector<pair<int, int>> stations (1);
    cin >> stations[0].first >> stations[0].second;
    for (int i = 1; i < numberOfStations; i++) {
        int a, b;
        cin >> a >> b;
        if (a != stations[i-1].first) {
            stations.push_back({a, b});
        }
    }
    double left { 0 };
    double right { pow(2, 0.5) * pow(10, 9) };
    while (right-left > 0.001) {
        double middle { (right+left)/2.0 };
        if (valid(highwayLength, stations, middle)) {
            right = middle;
        }
        else {
            left = middle+0.001;
        }
    }
    cout << (left+right)/2 << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}