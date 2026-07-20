#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    int barn { 0 };
    cin >> numberOfCows >> barn;
    struct Info {
        int weight;
        int position;
        int direction;
    };
    vector<Info> cows (numberOfCows);
    for (auto& a : cows) {
        cin >> a.weight >> a.position >> a.direction;
    }
    sort(cows.begin(), cows.end(), [](const auto& a, const auto& b) { return a.position < b.position; });
    float weightThreshold { 0 };
    for (const auto& a : cows) {
        weightThreshold += a.weight;
    }
    weightThreshold /= 2;
    int tempIndex { -1 };
    vector<pair<int, int>> finish;
    for (int i = 0; i < numberOfCows; i++) {
        if (cows[i].direction == -1) {
            tempIndex++;
            finish.push_back({cows[tempIndex].weight, cows[i].position});
        }
    }
    tempIndex = numberOfCows;
    for (int i = numberOfCows-1; i >= 0; i--) {
        if (cows[i].direction == 1) {
            tempIndex--;
            finish.push_back({cows[tempIndex].weight, barn-cows[i].position});
        }
    }
    sort(finish.begin(), finish.end(), [](const auto& a, const auto& b) { return a.second < b.second; });
    int timeThreshold { 0 };
    int w { 0 };
    for (const auto& a : finish) {
        timeThreshold = a.second;
        w += a.first;
        if (w >= weightThreshold) { break; }
    }
    int left { 0 };
    int right { 0 };
    int between { 0 };
    int answer { 0 };
    while (left != numberOfCows-1) {
        if (cows[left].direction == 1) {
            while (right != numberOfCows-1 && static_cast<float>(cows[right+1].position-cows[left].position)/2 <= timeThreshold) {
                right++;
                if (cows[right].direction == -1) {
                    between++;
                }
            } 
            answer += between;
            left++;
        }
        else {
            if (cows[left].direction == -1) {
                between--;
            }
            left++;
        }
    }
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
