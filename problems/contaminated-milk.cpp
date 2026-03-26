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
    int numberOfFriends { 0 };
    int numberOfTypes { 0 };
    int drinkTimes { 0 };
    int sickTimes { 0 };
    cin >> numberOfFriends >> numberOfTypes >> drinkTimes >> sickTimes;
    struct Info {
        int person;
        int milk;
        int time;
    };
    vector<Info> drinkRecords (drinkTimes);
    vector<Info> sickRecords (sickTimes);
    vector<set<int>> suspects (numberOfFriends);        

    for (int i = 0; i < drinkTimes; i++) {
        cin >> drinkRecords[i].person >> drinkRecords[i].milk >> drinkRecords[i].time;
    }
    for (int i = 0; i < sickTimes; i++) {
        cin >> sickRecords[i].person >> sickRecords[i].time;
    }
    for (int i = 0; i < sickTimes; i++) {
        for (int j = 0; j < drinkTimes; j++) {
            if (sickRecords[i].person == drinkRecords[j].person && sickRecords[i].time > drinkRecords[j].time) {
                suspects[sickRecords[i].person - 1].emplace(drinkRecords[j].milk);                
            }
        }
    }
    unordered_map<int, int> frequency(numberOfTypes);
    for (const auto& i : suspects) {
        for (const auto& j : i) {
            frequency[j-1]++;
        }
    }
    auto badMilkIndex = max_element(frequency.begin(), frequency.end(), [](const auto& a, const auto& b) { return a.second < b.second; });
    int badMilk = badMilkIndex->first;
    int answer { 0 };
    vector<int> checked;
    for (const auto& i : drinkRecords) {
        if (i.milk == badMilk && count(checked.begin(), checked.end(), i.person) == 0) {
            answer++;
            checked.push_back(i.person);
        }
    }
    cout << answer << "\n";
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}