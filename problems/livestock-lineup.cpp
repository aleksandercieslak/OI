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
    int numberOfConstraints { 0 };
    cin >> numberOfConstraints;
    vector<pair<string, string>> constraints (numberOfConstraints);
    for (int i = 0; i < numberOfConstraints; i++) {
        cin >> constraints[i].first >> constraints[i].second >> constraints[i].second >> constraints[i].second >> constraints[i].second >> constraints[i].second;
    }
    vector<string> cows {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    vector<string> permutation = cows;
    vector<string> answer (8);
    do {
        bool valid = true;
        for (const auto& a : constraints) {
            auto it = find(permutation.begin(), permutation.end(), a.first);
            int element = it - permutation.begin();
                if (element == 0){
                    if (permutation[element + 1] != a.second) { valid = false; }
                }
                else if (element == 7) {
                    if (permutation[element - 1] != a.second) { valid = false; }
                }
                else if (permutation[element + 1] != a.second && permutation[element - 1] != a.second) {
                    valid = false;
                }
        }
        if (valid) {
            for (int i = 0; i < 8; i++) {
                auto permIt = find(cows.begin(), cows.end(), permutation[i]);
                auto answerIt = find(cows.begin(), cows.end(), answer[i]);
                if (permIt != answerIt) {
                    if (permIt < answerIt) {
                        answer = permutation;
                    }
                    break;
                }
            }
        }
    } while (next_permutation(permutation.begin(), permutation.end()));
    for (int i = 0; i < 8; i++) {
        cout << answer[i] << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}