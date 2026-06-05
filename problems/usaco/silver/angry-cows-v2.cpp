#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> haybales, int radius) {
    int size { static_cast<int>(haybales.size()) };
    bool ret { false };
    for (int start = 0; start < size; start++) {
        int currentLeft { start };
        int currentRight { start };
        bool failure { false };
        while ((currentLeft > 0 || currentRight < size-1) && failure == false) {
            if (haybales[currentLeft-1] < haybales[currentLeft]-radius || haybales[currentRight+1] > haybales[currentRight]+radius) {
                failure = true;
                break;
            }
            int left { 0 };
            int right { size-1 };
            if (currentLeft-radius >= 0) {
                left = currentLeft-radius;
            }
            if (currentRight+radius < size) {
                right = currentRight+radius;
            }
            int tempRight { currentLeft };
            while (left <= tempRight) {
                if (currentLeft == 0) { break; }
                int middle { (left+tempRight)/2+1 };
                if (haybales[middle] > haybales[currentRight]-radius) {
                    tempRight = middle;
                }
                else if (haybales[middle] < haybales[currentRight]-radius) {
                    left = middle+1;
                }
                else {
                    currentLeft = middle;
                    break;
                }
            }
            int tempLeft { currentRight };
            while (tempLeft <= right) {
                if (currentRight == 0) { break; }
                int middle { (tempLeft+right)/2+1 };
                if (haybales[middle] > haybales[currentLeft]+radius) {
                    right = middle-1;
                }
                else if (haybales[middle] < haybales[currentLeft]+radius) {
                    tempLeft = middle;
                }
                else {
                    currentRight = middle;
                    break;
                }
            }
            radius++;
        }
        if (!failure) { ret = true; }
    }
    if (ret) { return true; }
    return false;
}

void solve() {
    int numberOfHaybales { 0 };
    cin >> numberOfHaybales;
    vector<int> haybales (numberOfHaybales);
    for (int i = 0; i < numberOfHaybales; i++) {
        cin >> haybales[i];
    }
    sort(haybales.begin(), haybales.end());
    int l { 0 };
    int r { static_cast<int>(haybales.size())-1 };
    while (l <= r) {
        int mid { (l+r)/2 };
        if (isPossible(haybales, mid)) {
            r = mid;
        }
        else {
            l = mid+1;
        }
    }
    cout << l << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}