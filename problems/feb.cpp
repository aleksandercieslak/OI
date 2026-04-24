#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCalls { 0 };
    string calls;
    cin >> numberOfCalls >> calls;
    int numberOfF { count(calls.begin(), calls.end(), 'F') };
    int general { 0 };
    int minPairs { 0 };
    long long maxPairs { 200000 };
    for (int i = 0; i < numberOfCalls; i++) {
        if (i < numberOfCalls-1 && calls[i] == calls[i+1] && (calls[i] == 'E' || calls[i] == 'B')) {
            general++;
        }
        else if (calls[i] == 'F') {
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
            }
            else {
                postfix = 'N';
            }
            vector<int> current;
            if (prefix == postfix && fCounter%2 == 0) {
                
            }
            else if (prefix == postfix && fCounter%2 == 1) {
            }
            else if (prefix != postfix && fCounter%2 == 0) {
            }
            else if (prefix != postfix && fCounter%2 == 1) {
            }
        }
    }  
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}