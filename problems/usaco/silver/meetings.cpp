#include <bits/stdc++.h>
using namespace std;

void solve() {
    int barn { 0 };
    int numberOfCows { 0 };
    cin >> numberOfCows >> barn;
    struct Info {
        int weight;
        int position;
        int direction;
        int time;
    };
    vector<Info> cows (numberOfCows);
    int totalWeight { 0 };
    for (auto& a : cows) {
        cin >> a.weight >> a.position >> a.direction;
        totalWeight += a.weight;
    }
    double weightTreshold { static_cast<double>(totalWeight)/static_cast<double>(2) };
    vector<Info> stats;
    sort(cows.begin(), cows.end(), [](const Info& a, const Info& b) { return a.position < b.position; });
    int counterLeft { -1 };
    int counterRight { -1 };
    for (int i = 0; i < numberOfCows; i++) {
        if (cows[i].direction == -1) {
            counterLeft++;
            Info temp;
            temp.time = i;
            temp.weight = cows[counterLeft].weight;
            temp.position = cows[i].position;
            temp.direction = cows[i].direction;
            stats.push_back(temp);
        }
        int j { numberOfCows-1-i };
        if (cows[j].direction == 1) {
            counterRight++;
            Info temp;
            temp.time = i;
            temp.weight = cows[numberOfCows-1-counterRight].weight;
            temp.position = cows[j].position;
            temp.direction = cows[j].direction;
            stats.push_back(temp);
        }
    }
    sort(stats.begin(), stats.end(), [](const Info& a, const Info& b) { return a.time < b.time; });
    int timeTreshold { 0 };
    int sum { 0 };
    for (int i = 0; i < numberOfCows; i++) {
        timeTreshold = stats[i].time;
        sum += stats[i].weight;
        if (sum >= weightTreshold) { break; }
    }
    int answer { 0 };
    vector<int> leftPos;
    for (int i = 0; i < numberOfCows; i++) {
        if (cows[i].direction == 1) {
            leftPos.push_back(cows[i].position);
        }
        else {
            while (leftPos.size() > 0 && leftPos[0] + 2 * timeTreshold < cows[i].position) {
                leftPos.erase(leftPos.begin());
            }
            answer += leftPos.size();
        }
    }
    cout << answer << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}