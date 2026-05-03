#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfTestCases { 0 };
    cin >> numberOfTestCases;
    for (int i = 0; i < numberOfTestCases; i++) {
        int roomWidth, roomHeight;
        int x1, y1, x2, y2;
        int tableWidth, tableHeight;
        cin >> roomWidth >> roomHeight;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> tableWidth >> tableHeight;

        int distanceToLeft { x1 };
        int distanceToRight { roomWidth-x2 };
        int distanceToBottom { y1 };
        int distanceToTop { roomHeight-y2 };

        int answerHorizontal { min(tableWidth-distanceToLeft, tableWidth-distanceToRight) };
        int answerVertical { min(tableHeight-distanceToBottom, tableHeight-distanceToTop) };

        if (tableWidth+x2-x1 > roomWidth && tableHeight+y2-y1 > roomHeight) {
            cout << -1 << "\n";
        }
        else if (tableWidth+x2-x1 <= roomWidth && tableHeight+y2-y1 > roomHeight) {
            cout << answerHorizontal << "\n";
        }
        else if (tableWidth+x2-x1 > roomWidth && tableHeight+y2-y1 <= roomHeight) {
            cout << answerVertical << "\n";
        }
        else {
            cout << min(answerHorizontal, answerVertical) << "\n";
        }

    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}