#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCalls { 0 };
    string calls;
    cin >> numberOfCalls >> calls;
    int general { 0 };
    long long minPairs { 0 };
    long long maxPairs { 0 };
    bool hasStepOne = false;
    bool hasEvenMin = false;
    bool hasOddMin = false;
    for (int i = 0; i < numberOfCalls; i++) {
        if (i < numberOfCalls-1 && calls[i] == calls[i+1] && (calls[i] == 'E' || calls[i] == 'B')) {
            general++;
        }
        else if (calls[i] == 'F') {
            long long bottomRange { 0 };
            long long topRange { 0 };
            int fCounter { 0 };
            char prefix;
            if (i != 0) {
                prefix = calls[i-1];
            }
            else {
                prefix = 'N';
            }
            while (calls[i] == 'F') {
                fCounter++;
                i++;
                if (i == numberOfCalls) { break; }
            }
            char postfix;
            if (i != numberOfCalls) {
                postfix = calls[i];
                i--;
            }
            else {
                postfix = 'N';
            }
            if (prefix != 'N' && postfix != 'N') {
                if (prefix == postfix && fCounter%2 == 0) {
                    bottomRange = 1;
                    topRange = fCounter + 1;
                }
                else if (prefix == postfix && fCounter%2 == 1) {
                    bottomRange = 0;
                    topRange = fCounter + 1;
                }
                else if (prefix != postfix && fCounter%2 == 0) {
                    bottomRange = 0;
                    topRange = fCounter;
                }
                else if (prefix != postfix && fCounter%2 == 1) {
                    bottomRange = 1;
                    topRange = fCounter;
                }
            }
            else if (postfix == 'N' && prefix == 'N') {
                bottomRange = 0;
                topRange = fCounter-1;
            }
            else {
                bottomRange = 0;
                topRange = fCounter;
            }
            if (prefix == 'N' || postfix == 'N') { hasStepOne = true; }
            if (bottomRange%2 == 0) { hasEvenMin = true; }
            else { hasOddMin = true; }
            minPairs += bottomRange;
            maxPairs += topRange;
        }
    }
    minPairs += general;
    maxPairs += general;
    int step;
    if (hasStepOne || (hasEvenMin && hasOddMin)) {
        step = 1;
    }
    else {
        step = 2;
    }
    cout << (maxPairs-minPairs)/step+1 << "\n";
    for (int i = minPairs; i <= maxPairs; i+=step)  {
        cout << i << "\n";
    } 
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}