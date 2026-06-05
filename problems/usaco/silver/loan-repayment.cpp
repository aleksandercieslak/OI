#include <bits/stdc++.h>
using namespace std;

bool valid(long long x, long long debt, long long days, long long minimum) {
    long long paid { 0 };
    while (paid < debt && days > 0) {
        long long y { (debt-paid)/x };
        if (y < minimum) {
            paid += minimum*days;
            if (paid >= debt) { return true; }
            else { return false; }
        }
        long long blockEdge { debt-y*x };
        long long skipLength { min((blockEdge-paid)/y+1, days) };
        paid += skipLength*y;
        days -= skipLength;
    }
    return paid >= debt;
}

void solve() {
    long long debt { 0 };
    long long days { 0 };
    long long minimum { 0 };
    cin >> debt >> days >> minimum;
    long long left { 1 };
    long long right { days };
    while (left < right) {
        long long middle { (left+right+1)/2 };
        if (valid(middle, debt, days, minimum)) {
            left = middle;
        }
        else {
            right = middle-1;
        }
    }
    cout << left << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}