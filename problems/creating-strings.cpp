#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using pii = pair<int,int>;
using vi  = vector<int>;
using vl  = vector<ll>;

#define F first
#define S second
#define all(x)     (x).begin(),(x).end()
#define pb         push_back
#define rep(i,a,b) for(int i=(a);i<(b);i++)

const int INF  = 1e9;
const ll  LINF = 1e18;
const int MOD  = 1e9+7;

void search(string word, vector<string>& answers, string& permutation, vector<bool>& checked) {
    if (permutation.size() == word.length()) {
        if (count(answers.begin(), answers.end(), permutation) == 0) {
            answers.push_back(permutation);
        }
    }
    else {
        for (int i = 0; i < static_cast<int>(word.length()); i++) {
            if (checked[i] == true) { continue; }
            checked[i] = true;
            permutation.push_back(word[i]);
            search(word, answers, permutation, checked);
            checked[i] = false;
            permutation.pop_back();
        }
    }
}

void solve() {
    string word;
    cin >> word;
    vector<string> answers;
    string permutation;
    vector<bool> checked (word.length());
    search(word, answers, permutation, checked);
    cout << answers.size() << "\n";
    for (int i = 0; i < static_cast<int>(answers.size()); i++) {
        cout << answers[i] << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}