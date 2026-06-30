#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    int numberOfStores { 0 };
    int numberOfFarmers { 0 };
    cin >> numberOfCows >> numberOfStores >> numberOfFarmers;
    vector<int> production (numberOfCows);
    vector<pair<int, int>> demand (numberOfStores);
    vector<int> rent (numberOfFarmers);
    for (int i = 0; i < numberOfCows; i++) {
        cin >> production[i];
    }
    for (int i = 0; i < numberOfStores; i++) {
        cin >> demand[i].first >> demand[i].second;
    }
    for (int i = 0; i < numberOfFarmers; i++) {
        cin >> rent[i];
    }
    sort(demand.begin(), demand.end(), [](pair<int, int> a, pair<int, int> b) { return a.second > b.second; });
    sort(production.begin(), production.end(), [](int a, int b) { return a > b; });
    sort(rent.begin(), rent.end(), [](int a, int b) { return a > b; });
    long long answer { 0 };
    bool over { false };
    while ((demand.size() > 0 || rent.size() > 0) && production.size() > 0) {
        int needed { production[0] };
        int running { 0 };
        int payout { 0 };
        int i { 0 };
        int loan { 0 };
        while (running < needed && demand.size() > 0) {
            if (i > static_cast<int>(demand.size())-1) {
                break;
            }
            else if (demand[i].first <= needed-running) {
                payout += demand[i].first * demand[i].second;
                running += demand[i].first;
                i++;
            }
            else {
                payout += (needed-running) * demand[i].second;
                loan = (needed-running);
                running = needed;
            }
        }
        while (rent.size() > 0 && payout <= rent[0]) {
            answer += rent[0];
            rent.erase(rent.begin());
            production.erase(production.end()-1);
            if (production.size() <= 0) {
                over = true;
                break;
            }
        }
        if (over) { break; }
        answer += payout;
        for (int j = 0; j < i; j++) {
            demand.erase(demand.begin()+j);
        }
        demand[0].first -= loan;
        production.erase(production.begin());
    }
    cout << answer << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}