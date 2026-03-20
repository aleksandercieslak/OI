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
    int numberOfAnimals { 0 };
    cin >> numberOfAnimals;
    vector<string> animalName (numberOfAnimals);
    vector<int> numberOfCharacteristics (numberOfAnimals);
    vector<vector<string>> characteristics (numberOfAnimals);
    vector<string> shared; 
    for (int i = 0; i < numberOfAnimals; i++) {
        cin >> animalName[i];
        cin >> numberOfCharacteristics[i];
        for (int j = 0; j < numberOfCharacteristics[i]; j++) {
            string thing;
            cin >> thing;
            characteristics[i].push_back(thing);
        }
        sort(characteristics[i].begin(), characteristics[i].end());
    }
    int counter { 0 };
    for (int i = 0; i < numberOfAnimals; i++) {
        for (int j = 0; j < numberOfAnimals; j++) {
            if (i != j) {
                shared.resize(min(characteristics[i].size(), characteristics[j].size()));
                auto iterator = set_intersection(characteristics[i].begin(), characteristics[i].end(), characteristics[j].begin(), characteristics[j].end(), shared.begin()) - shared.begin();
                int size = iterator;
                counter = max(counter, size);
                shared.clear();
            }
        }
    }
    cout << counter + 1 << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}