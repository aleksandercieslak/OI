#include <bits/stdc++.h>
using namespace std;

vector<int> firstBuckets (10);
vector<int> secondBuckets (10);
vector<int> subset;

vector<int> firstCopy (10);
vector<int> secondCopy (10);

unordered_set<int> measurements;


void search(int k) {
    if (static_cast<int>(subset.size()) == 4) {
        int measurement = 1000 - subset[0] + subset[1] - subset[2] + subset[3];
        measurements.emplace(measurement);
    }
    else if (k < static_cast<int>(subset.size()%2 == 0 ? firstCopy.size() : secondCopy.size())) {
        if (static_cast<int>(subset.size())%2 == 0) {
            search(k+1);
            subset.push_back(firstCopy[k]);
            secondCopy.push_back(firstCopy[k]);
            firstCopy.erase(firstCopy.begin()+k);
            search(0);
            subset.pop_back();
            firstCopy.insert(firstCopy.begin()+k, secondCopy.back());
            secondCopy.erase(secondCopy.end()-1);
        }
        if (static_cast<int>(subset.size())%2 == 1) {
            search(k+1);
            subset.push_back(secondCopy[k]);
            firstCopy.push_back(secondCopy[k]);
            secondCopy.erase(secondCopy.begin()+k);
            search(0);
            subset.pop_back();
            secondCopy.insert(secondCopy.begin()+k, firstCopy.back());
            firstCopy.erase(firstCopy.end()-1);
        }
    }
}

void solve() {
    for (int i = 0; i < 10; i++) {
        cin >> firstBuckets[i];
    }
    for (int i = 0; i < 10; i++) {
        cin >> secondBuckets[i];    
    }
    firstCopy = firstBuckets;
    secondCopy = secondBuckets;
    search(0);
    cout << static_cast<int>(measurements.size()) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}