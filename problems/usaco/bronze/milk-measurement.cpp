#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using pii = pair<int,int>;
using vi  = vector<int>;
using vl  = vector<ll>;

#define F first
#define S second
#define all(x)     (x).begin(),(x).end()
#define pb         push_back
#define rep(i,a,b) for(int i=(a);i<(b);i++)

const int INF  = 1e9;
const ll  LINF = 1e18;
const int MOD  = 1e9+7;

void solve() {
    int numberOfChanges { 0 };
    int numberOfMeasurements { 0 };
    string rawOutputNumber;
    struct Info {
        int day;
        string cow;
        int output;
        bool operator<(const Info& Other) const {
            return day < Other.day;
        }
    };
    vector<Info> measurements;
    map<string, int> currentOutput {{"Bessie", 7}, {"Elsie", 7}, {"Mildred", 7}};
    set<string> currentDisplay {"Bessie", "Elsie", "Mildred"};
    set<string> previousDisplay {"Bessie", "Elsie", "Mildred"};
    int largestNumber { 0 };
    cin >> numberOfMeasurements;
    for (int i = 0; i < numberOfMeasurements; i++) {
        Info temporary;
        cin >> temporary.day >> temporary.cow >> rawOutputNumber;
        temporary.output = stoi(rawOutputNumber);
        measurements.push_back(temporary);
    }
    sort(measurements.begin(), measurements.end());
    for (int i = 0; i < numberOfMeasurements; i++) {
        if (measurements[i].cow == "Bessie") {
            currentOutput["Bessie"] += measurements[i].output;
        }
        else if (measurements[i].cow == "Elsie") {
            currentOutput["Elsie"] += measurements[i].output;
        }
        else if (measurements[i].cow == "Mildred") {
            currentOutput["Mildred"] += measurements[i].output;
        }
        largestNumber = max(currentOutput["Bessie"], max(currentOutput["Elsie"], currentOutput["Mildred"]));
        currentDisplay.clear();
        for (auto& [name, value] : currentOutput) if (value == largestNumber) { currentDisplay.insert(name); }
        if (currentDisplay != previousDisplay) {
            numberOfChanges++;
            previousDisplay = currentDisplay;
        }
    }
    cout << numberOfChanges << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}