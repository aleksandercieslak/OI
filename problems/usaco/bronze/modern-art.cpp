#include <bits/stdc++.h>
using namespace std;

void solve() {
    int side { 0 };
    cin >> side;
    vector<string> canvas (side);
    set<char> colors;
    for (int i = 0; i < side; i++) {
        cin >> canvas[i];
        for (int j = 0; j < side; j++) {
            colors.insert(canvas[i][j]);
        }
    }
    int notFirstCounter { 0 };
    for (char color : colors) {
        if (color == '0') { continue; }
        int leftX { side };
        int rightX { 0 };
        int bottomY { 0 };
        int topY { side };
        for (int i = 0; i < side; i++) {
            for (int j = 0; j < side; j++) {
                if (canvas[i][j] == color) {
                    if (i < topY) { topY = i; }
                    if (i > bottomY) { bottomY = i; }
                    if (j < leftX) { leftX = j; }
                    if (j > rightX) { rightX = j; }
                }
            }
        }
        if ((bottomY != side-1 && leftX != 0 && canvas[bottomY][leftX] == color && canvas[bottomY][leftX-1] == canvas[bottomY+1][leftX] && canvas[bottomY+1][leftX] == canvas[bottomY+1][leftX-1]) ||
        (bottomY != side-1 && rightX != side-1 && canvas[bottomY][rightX] == color && canvas[bottomY][rightX+1] == canvas[bottomY+1][rightX] && canvas[bottomY+1][rightX] == canvas[bottomY+1][rightX+1]) ||
        (topY != 0 && leftX != 0 && canvas[topY][leftX] == color && canvas[topY][leftX-1] == canvas[topY-1][leftX] && canvas[topY-1][leftX] == canvas[topY-1][leftX-1]) ||
        (topY != 0 && rightX != side-1 && canvas[topY][rightX] == color && canvas[topY][rightX+11] == canvas[topY-1][rightX] && canvas[topY-1][rightX] == canvas[topY-1][rightX+1])) {
            notFirstCounter++;
        }
    }
    cout << static_cast<int>(colors.size())-1 - notFirstCounter << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}