#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    int numberOfRecords { 0 };
    string isSick;
    struct Info {
        int time;
        int one;
        int two;
    };
    int potentialZero { 0 };
    int smallestK { 250 };
    int largestK { 0 };
    cin >> numberOfCows >> numberOfRecords >> isSick;
    vector<Info> records (numberOfRecords);
    for (int i = 0; i < numberOfRecords; i++) {
        cin >> records[i].time >> records[i].one >> records[i].two;
    }
    sort(records.begin(), records.end(), [](const auto& a, const auto& b) { return a.time < b.time; } );
    for (int k = 0; k <= 251; k++) {
        for (int i = 1; i <= numberOfCows; i++) {
            vector<int> handshakes (numberOfCows);
            string simulation;
            for (int j = 0; j < numberOfCows; j++) { simulation.push_back('0'); };
            simulation[i-1] = '1';
            for (const auto& a : records) {
                if (simulation[a.one - 1] == '1' && simulation[a.two - 1] == '0' && handshakes[a.one - 1] < k) {
                    simulation[a.two - 1] = '1';
                    handshakes[a.one - 1]++;
                }
                else if (simulation[a.two - 1] == '1' && simulation[a.one - 1] == '0' && handshakes[a.two - 1] < k) {
                    simulation[a.one - 1] = '1';
                    handshakes[a.two - 1]++;
                }
            }
            if (simulation == isSick && k == 251) {
                potentialZero++;
                smallestK = min(k, smallestK);
                largestK = max(k, largestK);
            }
            else if (simulation == isSick) {
                smallestK = min(k, smallestK);
                largestK = max(k, largestK);

            }
        }
    }
    if (largestK == 251) {
        cout << potentialZero << " " << smallestK << " " << "Infinity" << "\n";
    }
    else {
        cout << potentialZero << " " << smallestK << " " << largestK << "\n";
    }    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}