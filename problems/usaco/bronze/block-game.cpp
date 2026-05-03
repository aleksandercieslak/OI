#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfBoards { 0 };
    cin >> numberOfBoards;
    vector<char> neededLetters(2000);
    vector<int> numberOfLetters(26);
    vector<pair<string, string>> boards(numberOfBoards);
    for (int i = 0; i < numberOfBoards; i++) {
        cin >> boards[i].first >> boards[i].second;
    }
    for (int i = 0; i < numberOfBoards; i++) {
        set_union(boards[i].first.begin(), boards[i].first.end(), boards[i].second.begin(), boards[i].second.end(), back_inserter(neededLetters));
    }
    for (char i = 'a'; i <= 'z'; i++) {
        numberOfLetters[i - 'a'] += count(neededLetters.begin(), neededLetters.end(), i);
    }
    for (int i = 0; i < 26; i++) {
        cout << numberOfLetters[i] << "\n";
    }
    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}