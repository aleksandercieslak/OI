#include <bits/stdc++.h>
using namespace std;

void solve() {
    int stringLength { 0 };
    string mailboxes;
    cin >> stringLength >> mailboxes;
    for (int i = 1; i <= stringLength; i++) {
        unordered_set<string> checked;
        bool isValid = true;
        for (int j = 0; j <= stringLength-i; j++) {
            string temp = mailboxes.substr(j, i);
            if (checked.count(temp) == 1) {
                isValid = false;
                break;
            }
            else {
                checked.insert(temp);
            }
        }
        if (isValid) {
            cout << i << "\n";
            break;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}