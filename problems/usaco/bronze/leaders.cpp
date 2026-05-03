#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    cin >> numberOfCows;
    string breed;
    cin >> breed;
    vector<int> E (numberOfCows);
    for (int i = 0; i < numberOfCows; i++) {
        cin >> E[i];
    }
    int counterG = count(breed.begin(), breed.end(), 'G');
    int counterH = count(breed.begin(), breed.end(), 'H');
    auto firstG = find(breed.begin(), breed.end(), 'G');
    auto firstH = find(breed.begin(), breed.end(), 'H');
    int indexG = distance(breed.begin(), firstG);
    int indexH = distance(breed.begin(), firstH);
    int possiblePairs { 0 };
    if (count(firstG, breed.begin()+E[indexG], 'G') == counterG) {
        possiblePairs += count(breed.begin(), firstG, 'H');
    }
    if (count(firstH, breed.begin()+E[indexH], 'H') == counterH) {
        possiblePairs += count(breed.begin(), firstH, 'G');
    }
    cout << possiblePairs << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}