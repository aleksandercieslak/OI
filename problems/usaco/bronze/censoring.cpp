#include <bits/stdc++.h>
using namespace std;

void solve() {
    string magazine;
    string phrase;
    cin >> magazine >> phrase;
    while (magazine.find(phrase) != string::npos) {
        magazine.erase(magazine.find(phrase), phrase.length());
    }
    cout << magazine << "\n";   
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}