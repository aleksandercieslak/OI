#include <bits/stdc++.h>
using namespace std;

void solve() {
    int firstXBottom, firstYBottom, firstXTop, firstYTop;
    int secondXBottom, secondYBottom, secondXTop, secondYTop;
    int truckXBottom, truckYBottom, truckXTop, truckYTop;
    cin >> firstXBottom >> firstYBottom >> firstXTop >> firstYTop;
    cin >> secondXBottom >> secondYBottom >> secondXTop >> secondYTop;
    cin >> truckXBottom >> truckYBottom >> truckXTop >> truckYTop;

    int firstBillboardArea { (firstXTop - firstXBottom)*(firstYTop - firstYBottom) };
    int secondBillboardArea { (secondXTop - secondXBottom)*(secondYTop - secondYBottom) };

    int firstObfuscatedArea { 0 };
    int secondObfuscatedArea { 0 };
    
    if (truckXTop > firstXBottom && truckYTop > firstYBottom && truckXBottom < firstXTop && truckYBottom < firstYTop) {
        int topPoint { min(firstYTop, truckYTop) };
        int bottomPoint { max(firstYBottom, truckYBottom) };
        int verticalSide { abs(topPoint-bottomPoint) };

        int rightPoint { min(firstXTop, truckXTop) };
        int leftPoint { max(firstXBottom, truckXBottom) };
        int horizontalSide { abs(rightPoint-leftPoint) };

        firstObfuscatedArea = verticalSide*horizontalSide;
    }

    if (truckXTop > secondXBottom && truckYTop > secondYBottom && truckXBottom < secondXTop && truckYBottom < secondYTop) {
        int topPoint { min(secondYTop, truckYTop) };
        int bottomPoint { max(secondYBottom, truckYBottom) };
        int verticalSide { abs(topPoint-bottomPoint) };

        int rightPoint { min(secondXTop, truckXTop) };
        int leftPoint { max(secondXBottom, truckXBottom) };
        int horizontalSide { abs(rightPoint-leftPoint) };

        secondObfuscatedArea = verticalSide*horizontalSide;
    }

    int answer { firstBillboardArea-firstObfuscatedArea + secondBillboardArea-secondObfuscatedArea };
    cout << answer << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}