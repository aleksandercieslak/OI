#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfEntries { 0 };
    cin >> numberOfEntries;
    unordered_map<string, int> cows {
        {"Bessie", 0},
        {"Elsie", 0},
        {"Daisy", 0},
        {"Gertie", 0},
        {"Annabelle", 0},
        {"Maggie", 0},
        {"Henrietta", 0}
    };
    for (int i = 0; i < numberOfEntries; i++) {
        string first;
        int second;
        cin >> first >> second;
        cows[first] += second;
    }
    auto it { min_element(cows.begin(), cows.end(), [](const auto& a, const auto& b) { return a.second < b.second; }) };
    int minProd { 10000 };
    string name;
    int counter { 1 };
    for (auto a : cows) {
        if (a.second > it->second && a.second < minProd) {
            minProd = a.second;
            name = a.first;
            counter = 1;
        }
        else if (a.second == minProd) {
            counter++;
        }
    }
    if (name.empty() || counter > 1) {
        cout << "Tie\n";
    }
    else {
        cout << name << "\n";
    }
}

int main() {
     cin.tie(0)->sync_with_stdio(0);
     solve();
}