#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfRectangles { 0 };
    int k { 0 };
    cin >> numberOfRectangles >> k;
    vector<vector<int>> barn (1002, vector<int>(1002));
    for (int i = 0; i < numberOfRectangles; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = y1; j < y2; j++) {
            barn[j][x1]++;
            barn[j][x2]--;
        } 
    }
    int counter { 0 };
    for (int i = 0; i < 1001; i++) {
        if (barn[i][0] == k) { counter++; }
        for (int j = 1; j < 1001; j++) {
            barn[i][j] += barn[i][j-1];
            if (barn[i][j] == k) {
                counter++;
            }
        }
    }
    cout << counter << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}