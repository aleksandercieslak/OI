#include <bits/stdc++.h>
using namespace std;

void solve() {
    int badBottomX, badBottomY, badTopX, badTopY;
    int goodBottomX, goodBottomY, goodTopX, goodTopY;
    cin >> badBottomX >> badBottomY >> badTopX >> badTopY;
    cin >> goodBottomX >> goodBottomY >> goodTopX >> goodTopY;

    int badHorizontal { badTopX-badBottomX };
    int badVertical { badTopY-badBottomY };

    if (goodBottomX <= badBottomX && goodTopX >= badTopX && (goodTopX >= badTopX || goodBottomX <= badBottomX)) {
        if (goodTopY >= badBottomY && goodBottomY <= badTopY && (goodTopY >= badTopY || goodBottomY <= badBottomY)) {
            int vertical { abs(min(goodTopY, badTopY)-badBottomY) };
            badVertical -= vertical;
        }
    }
    else if (goodBottomY <= badBottomY && goodTopY >= badTopY && (goodTopY >= badTopY || goodBottomY <= badBottomY)) {
        if (goodTopX >= badBottomX && goodBottomX <= badTopX && (goodTopX >= badTopX || goodBottomX <= badBottomX)) {
            int horizontal { abs(min(goodTopX, badTopX)-badBottomX) };
            badHorizontal -= horizontal;
        }
    }

    cout << badHorizontal*badVertical << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}