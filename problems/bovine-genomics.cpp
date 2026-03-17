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
    cin >> numberOfCows;
    int genomeLength { 0 };
    cin >> genomeLength;
    vector<string> spottyCows (numberOfCows);
    vector<string> plainCows (numberOfCows);
    vector<char> potentialLetters;
    int answer { 0 };
    int counter { 0 };
    for (int i = 0; i < numberOfCows; i++) {
        cin >> spottyCows[i];
    }
    for (int i = 0; i < numberOfCows; i++) {
        cin >> plainCows[i];
    }
    for (int i = 0; i < genomeLength; i++) {
        for (int j = 0; j < numberOfCows; j++) {
            potentialLetters.push_back(spottyCows[j][i]);
        }
        for (int j = 0; j < numberOfCows; j++) {
            if (count(potentialLetters.begin(), potentialLetters.end(), plainCows[j][i]) == 0) {
                counter++;
            }
        }
        if (counter == numberOfCows) {
            answer++;
        }
        potentialLetters.clear();
        counter = 0;
    }
    cout << answer << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}