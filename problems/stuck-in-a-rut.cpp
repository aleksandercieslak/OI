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
    struct Info {
        char direction;
        int x;
        int y;
        int numberOfSteps;
        vector<int> steps;
    };
    vector<Info> cow(numberOfCows);
    for (int i = 0; i < numberOfCows; i++) {
        cin >> cow[i].direction >> cow[i].x >> cow[i].y;
    }
    for (int i = 0; i < numberOfCows; i++) {
        for (int j = 0; j < numberOfCows; j++) {
            if (cow[i].direction != cow[j].direction) {
                if (cow[i].direction == 'N') { 
                    if (cow[i].y < cow[j].y && cow[i].x > cow[j].x) {
                         if (abs(cow[j].x - cow[i].x) < abs(cow[i].y - cow[j].y)) {
                            cow[i].steps.push_back(cow[j].y - cow[i].y);
                        }
                    }
                }
                else if (cow[i].direction == 'E') {
                    if (cow[i].x < cow[j].x && cow[i].y > cow[j].y) {
                        if (abs(cow[j].x - cow[i].x) > abs(cow[i].y - cow[j].y)) {
                            cow[i].steps.push_back(cow[j].x - cow[i].x);
                        }
                    }
                }
            }
            else if (cow[i].direction == cow[j].direction) {
                if (cow[i].direction == 'N') {
                    if (cow[i].x == cow[j].x && cow[i].y < cow[j].y) {
                        cow[i].steps.push_back(cow[j].y - cow[i].y);
                    }
                }
                if (cow[i].direction == 'E') {
                    if (cow[i].y == cow[j].y && cow[i].x < cow[j].x) {
                        cow[i].steps.push_back(cow[j].x - cow[i].x);
                    }
                }
            }
        }
    }
    for (int i = 0; i < numberOfCows; i++) {
        if (cow[i].steps.empty()) {
            cout << "Infinity\n";
        }
        else { cout << *min_element(cow[i].steps.begin(), cow[i].steps.end()) << "\n"; }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}