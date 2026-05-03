#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfRelations { 0 };
    cin >> numberOfRelations;
    string firstCow, secondCow;
    cin >>  firstCow >> secondCow;
    unordered_map<string, string> mother;
    for (int i = 0; i < numberOfRelations; i++) {
        string mom, daughter;
        cin >> mom >> daughter;
        mother[daughter] = mom;
        mother[mom] = "NONE";
    }

    string descendant;
    string ancestor;

    string current { firstCow };
    int greatCounter { -2 };
    string type;
    while (mother[current] != "NONE") {
        if (current == secondCow) {
            type = "MOTHER";
            break;
        }
        else if (mother[secondCow] == current) {
            type = "AUNT";
            break;
        }
        else if (mother[mother[secondCow]] == current) {
            type = "COUSIN";
            break;
        }
        current = mother[current];
        greatCounter++;
    }
    if (mother[current] == "NONE") {
        if (current == secondCow) {
            type = "MOTHER";
        }
        else if (mother[secondCow] == current) {
            type = "AUNT";
        }
        else if (mother[mother[secondCow]] == current) {
            type = "COUSIN";
        }       
    }



    if (type.empty()) {
        current = secondCow;
        greatCounter = -2;
        while (mother[current] != "NONE") {
            if (current == firstCow) {
                type = "MOTHER";
                break;
            }
            else if (mother[firstCow] == current) {
                type = "AUNT";
                break;
            }
            else if (mother[mother[firstCow]] == current) {
                type = "COUSIN";
                break;
            }
            current = mother[current];
            greatCounter++;
        }
        if (mother[current] == "NONE") {
            if (current == firstCow) {
                type = "MOTHER";
            }
            else if (mother[firstCow] == current) {
                type = "AUNT";
            }
            else if (mother[mother[firstCow]] == current) {
                type = "COUSIN";
            }       
        }
        descendant = secondCow;
        ancestor = firstCow;
    }
    else { descendant = firstCow; ancestor = secondCow; }

    if (type.empty()) { cout << "NOT RELATED" << "\n"; }
    else if (type == "COUSIN") { cout << "COUSINS" << "\n"; }
    else if (type == "AUNT") {
        if (greatCounter == -1) { cout << ancestor << " is the sister of " << descendant << "\n"; }
        else if (greatCounter == 0) { cout << ancestor << " is the aunt of " << descendant << "\n"; }
        else if (greatCounter > 0) {
            string title;
            for (int i = 0; i < greatCounter; i++) {
                title += "great-";
            }
            title += "aunt";
            cout << ancestor << " is the " << title << " of " << descendant << "\n";
        }
    }
    else if (type == "MOTHER") {
        if (greatCounter == -1) { cout << ancestor << " is the mother of " << descendant << "\n"; }
        else if (greatCounter == 0) { cout << ancestor << " is the grand-mother of " << descendant << "\n"; }
        else if (greatCounter > 0) {
            string title;
            for (int i = 0; i < greatCounter; i++) {
                title += "great-";
            }
            title += "grand-mother";
            cout << ancestor << " is the " << title << " of " << descendant << "\n";
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}