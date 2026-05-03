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
    int geneLength { 0 };
    int answer { 0 };
    cin >> numberOfCows >> geneLength;
    vector<string> spottyGene (numberOfCows);
    vector<string> plainGene (numberOfCows);
    for (int i = 0; i < numberOfCows; i++) {
        cin >> spottyGene[i];
    }
    for (int i = 0; i < numberOfCows; i++) {
        cin >> plainGene[i];
    }
    for (int j = 0; j < geneLength; j++) {
        for (int k = j+1; k < geneLength; k++) {
            for (int m = k+1; m < geneLength; m++) {
                set<array<char, 3>> spottyCombinations;
                set<array<char, 3>> plainCombinations;
                vector<array<char, 3>> difference;
                for (int i = 0; i < numberOfCows; i++) {
                spottyCombinations.insert({spottyGene[i][j], spottyGene[i][k], spottyGene[i][m]});
                plainCombinations.insert({plainGene[i][j], plainGene[i][k], plainGene[i][m]});              
                };
                set_difference(spottyCombinations.begin(), spottyCombinations.end(), plainCombinations.begin(), plainCombinations.end(), back_inserter(difference));
                if (difference.size() == spottyCombinations.size()) {
                    answer++;
                }
            }
        }
    }
    cout << answer << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}