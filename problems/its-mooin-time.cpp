#include <bits/stdc++.h>
using namespace std;

void solve() {
    int stringLength { 0 };
    int frequency { 0 };
    string contest;
    cin >> stringLength >> frequency >> contest;
    vector<char> alphabet {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    unordered_map<string, int> moo;
    for (int i = 0; i < stringLength; i++) {
        string temp = contest;
        for (char a : alphabet) {
            temp[i] = a;
            unordered_map<string, int> instance;
            for (int j = 0; j < stringLength-2; j++) {
                if (temp[j+1] == temp[j+2] && temp[j+1] != temp[j]) {
                    string key;
                    key += temp[j];
                    key += temp[j+1];
                    key += temp[j+2];
                    instance[key]++;
                }
            }
            for (auto x : instance) {
                moo[x.first] = max(x.second, moo[x.first]);
            }
        }
    }
    int counter { 0 };
    vector<string> answers;
    for (auto a : moo) {
        if (a.second >= frequency) {
            counter++;
            answers.push_back(a.first);
        }
    }
    cout << counter << "\n";
    sort(answers.begin(), answers.end());
    for (auto a : answers) {
        cout << a << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}