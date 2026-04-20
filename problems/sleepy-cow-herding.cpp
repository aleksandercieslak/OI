#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> position (3);
    cin >> position[0] >> position[1] >> position[2];
    int worstCase;
    int bestCase;
    sort(position.begin(), position.end());
    if (position[0]+1 == position[1] && position[1]+1 == position[2]) {
        bestCase = 0;
        worstCase = 0;
    }
    else if (position[0]+2 == position[1]) {
        bestCase = 1;
        if (position[1]+1 == position[2]) {
            worstCase = 1;
        }
        else {
            worstCase = position[2]-position[1]-1;
        }
    }
    else if (position[1]+2 == position[2]) {
        bestCase = 1;
        if (position[0]+1 == position[1]) {
            worstCase = 1;
        }
        else {
            worstCase = position[1]-position[0]-1;
        }
    }
    else {
        bestCase = 2;
        if (position[1]-position[0] < position[2]-position[1]) {
            worstCase = position[2]-position[1]-1;
        }
        else {
            worstCase = position[1]-position[0]-1;
        }
    }
    cout << bestCase << "\n" << worstCase << "\n"; 
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}