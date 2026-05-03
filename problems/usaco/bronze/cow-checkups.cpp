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
    int numberOfCows { 0 };
    int matchCounter { 0 };
    int validCombinations { 0 };
    cin >> numberOfCows;
    vector<int> cowSpecies (numberOfCows);
    vector<int> requiredSpecies (numberOfCows);
    for (int i = 0; i < numberOfCows; i++) {
        cin >> cowSpecies[i];
    }
    for (int i = 0; i < numberOfCows; i++) {
        cin >> requiredSpecies[i];
    }
    for (int i = 0; i < numberOfCows+1; i++) {
        for (int j = 0; j < numberOfCows; j++) {
            for (int k = 0; k < numberOfCows; k++) {
                if (j <= k) {
                    vector<int> temp = cowSpecies;
                    reverse(temp.begin() + j, temp.begin() + k + 1);
                    for (int l = 0; l < numberOfCows; l++) {
                        if (temp[l] == requiredSpecies[l]) {
                            matchCounter++;
                        }
                    }
                    if (matchCounter == i) {
                        validCombinations++;
                    }
                    matchCounter = 0;
                }
            }
        }
        cout << validCombinations << "\n";
        validCombinations = 0;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}