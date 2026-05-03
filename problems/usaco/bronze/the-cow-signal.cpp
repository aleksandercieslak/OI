#include <bits/stdc++.h>
using namespace std;

void solve() {
    int M = 0;
    int N = 0;
    int K = 0;
    cin >> M >> N >> K;
    vector<string> sheet (M);
    for (int i = 0; i < M; i++) {
        cin >> sheet[i];
    }
        for (int i = 0; i < M*K; i++) {
            for (int j = 0; j < N*K; j++) {
                cout << sheet[i/K][j/K];
            }
            cout << "\n";
        }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}