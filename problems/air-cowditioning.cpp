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

int answer { 10000 };
struct CowInfo {
    int firstStall;
    int lastStall;
    int requirement;
};
struct ConditionerInfo {
    int firstStall;
    int lastStall;
    int difference;
    int money;
};
int numberOfCows { 0 };
int numberOfConditioners { 0 };
vector<CowInfo> cows (numberOfCows);
vector<ConditionerInfo> conditioners (numberOfConditioners);
vector<ConditionerInfo> subset;
vector<int> standard (101);
vector<bool> isCow (101);

void search(int k) {
    if (k == numberOfConditioners) {
        vector<int> cooling (101);
        bool valid = true;
        int requiredMoney { 0 };
        for (int i = 0; i < static_cast<int>(subset.size()); i++) {
            requiredMoney += subset[i].money;
            for (int j = subset[i].firstStall; j <= subset[i].lastStall; j++) {
                cooling[j] += subset[i].difference;
            }
        }
        for (int i = 0; i < 100; i++) {
            if (standard[i] > cooling[i] && isCow[i]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            answer = min(answer, requiredMoney);
        }
    }
    else {
        search(k+1);
        subset.push_back(conditioners[k]);
        search(k+1);
        subset.pop_back();
    }
}

void solve() {
    cin >> numberOfCows >> numberOfConditioners;
    cows.resize(numberOfCows);
    conditioners.resize(numberOfConditioners);
    for (int i = 0; i < numberOfCows; i++) {
        cin >> cows[i].firstStall >> cows[i].lastStall >> cows[i].requirement;
        for (int j = cows[i].firstStall; j <= cows[i].lastStall; j++) {
            standard[j] = cows[i].requirement;
            isCow[j] = true;
        }
    }
    for (int i = 0; i < numberOfConditioners; i++) {
        cin >> conditioners[i].firstStall >> conditioners[i].lastStall >> conditioners[i].difference >> conditioners[i].money;        
    }
    search(0);
    cout << answer << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}