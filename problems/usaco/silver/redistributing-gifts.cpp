#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    cin >> numberOfCows;
    vector<vector<int>> wanted (numberOfCows);
    for (int i = 0; i < numberOfCows; i++) {
        bool stop { false };
        for (int j = 0; j < numberOfCows; j++) {
            int a;
            cin >> a;
            if (a-1 == i) {
                stop = true;
            }
            if (!stop) {
                wanted[i].push_back(a-1);
            }
        }
    }
    vector<vector<int>> connections (numberOfCows); 
    for (int i = 0; i < numberOfCows; i++) {
        for (const int& a : wanted[i]) {
            connections[a].push_back(i);
        }  
    }
    for (int i = 0; i < numberOfCows; i++) {
        vector<bool> visited (numberOfCows);
        stack<int> dfsStack;
        dfsStack.push(i);
        visited[i] = true;
        while (!dfsStack.empty()) {
            int temp { dfsStack.top() };
            dfsStack.pop();
            for (const int& a : connections[temp]) {
                if (!visited[a]) {
                    dfsStack.push(a);
                    visited[a] = true;
                }
            }
        }
        bool found { false };
        for (const int& a : wanted[i]) {
            if (visited[a]) {
                found = true;
                cout << a+1 << "\n";
                break;
            }
        }
        if (!found) {
            cout << i+1 << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
