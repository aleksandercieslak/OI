#include <bits/stdc++.h>
using namespace std;

void solve() {
    int arrayLength { 0 };
    int divisor { 0 };
    cin >> arrayLength >> divisor;
    vector<int> numbers (arrayLength);
    for (int i = 0; i < arrayLength; i++) {
        cin >> numbers[i];
    }
    vector<int> remaining (arrayLength);
    vector<int> wantedShift (arrayLength);
    for (int i = 0; i < arrayLength; i++) {
        remaining[i] = numbers[i]%divisor;
        if (remaining[i] > divisor/2) {
            wantedShift[i] = -(divisor-remaining[i]);
        }
        else {
            wantedShift[i] = remaining[i];
        }
    }
    vector<int> negativeShift;
    vector<int> positiveShift;
    int numberOfZeros { 0 };
    for (int i = 0; i < arrayLength; i++) {
        if (wantedShift[i] < 0) {
            negativeShift.push_back(wantedShift[i]);
        }
        else if (wantedShift[i] > 0) {
            positiveShift.push_back(wantedShift[i]);
        }
        else {
            numberOfZeros++;
        }
    }
    sort(negativeShift.begin(), negativeShift.end(), [](int a, int b) { return a > b; });
    sort(positiveShift.begin(), positiveShift.end());

    int x;
    int negativeSize { static_cast<int>(negativeShift.size()) };
    int positiveSize { static_cast<int>(positiveShift.size()) };
    if (negativeSize > positiveSize+numberOfZeros) {
        int limit { (negativeSize-positiveSize)/2+1 }; 
        x = *(negativeShift.begin()+limit-1);
    }
    else if (positiveSize > negativeSize+numberOfZeros) {
        int limit { (positiveSize-negativeSize)/2+1 }; 
        x = *(positiveShift.begin()+limit-1);
    }
    else { x = 0; }
    int minBoredom { 0 };
    for (int i = 0; i < arrayLength; i++) {
        minBoredom += abs(wantedShift[i]-x);
    }
    cout << minBoredom << "\n";    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int numberOfTestCases { 0 };
    cin >> numberOfTestCases;
    for (int i = 0; i < numberOfTestCases; i++) {
        solve();
    }
}