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

string findWord(vector<pair<string, string>>& container, string type) {
    for (auto& a : container) {
        if (a.second == type) {
            auto iterator = find(container.begin(), container.end(), a);
            container.erase(iterator);
            return a.first;
        }
    }
    return "";
}


void solve() {
    int numberOfInstances { 0 };
    cin >> numberOfInstances;
    for (int q = 0; q < numberOfInstances; q++) {
        int answer { 0 };
        string sentence;
        int numberOfWords { 0 };
        int numberOfCommas { 0 };
        int numberOfPeriods { 0 };
        cin >> numberOfWords >> numberOfCommas >> numberOfPeriods;
        vector<pair<string, string>> words (numberOfWords);
        int nouns { 0 };
        int transitiveVerbs { 0 };
        int intransitiveVerbs { 0 };
        int conjunctions { 0 };
        for (int i = 0; i < numberOfWords; i++) {
            cin >> words[i].first >> words[i].second;
            if (words[i].second == "noun") {
                nouns++;
            }
            if (words[i].second == "transitive-verb") {
                transitiveVerbs++;
            }
            if (words[i].second == "intransitive-verb") {
                intransitiveVerbs++;
            }
            if (words[i].second == "conjunction") {
                conjunctions++;
            }
        }
        for (int i = 0; i <= min(nouns, intransitiveVerbs); i++) {
            for (int j = 0; j <= min(nouns-i, transitiveVerbs); j++) {
                for (int k = 0; k <= min(nouns-i-j, numberOfCommas); k++) {
                    if (j > 0) {
                        int newNouns = i+2*j+k;
                        int newIntransitiveVerbs = i;
                        int newTransitiveVerbs = j;
                        int newConjunctions = min(conjunctions, (i+j)/2);
                        int newCommas = k;
                        int newPeriods = i+j-newConjunctions;
                        if (newNouns <= nouns && newIntransitiveVerbs <= intransitiveVerbs && newTransitiveVerbs <= transitiveVerbs && newConjunctions <= conjunctions && newCommas <= numberOfCommas && newPeriods <= numberOfPeriods) {
                            answer = max(newNouns+newIntransitiveVerbs+newTransitiveVerbs+newConjunctions, answer);
                            if (answer == newNouns+newIntransitiveVerbs+newTransitiveVerbs+newConjunctions) {
                                sentence = "";
                                vector<string> sentences (i+j);
                                vector<pair<string, string>> temporary = words;
                                bool wasAdded = false;
                                for (int l = 0; l < i; l++) {
                                    sentences[l] += findWord(temporary, "noun");
                                    sentences[l] += " ";
                                    sentences[l] += findWord(temporary, "intransitive-verb");
                                }
                                for (int l = i; l < i+j; l++) {
                                    sentences[l] += findWord(temporary, "noun");
                                    sentences[l] += " ";
                                    sentences[l] += findWord(temporary, "transitive-verb");
                                    sentences[l] += " ";
                                    sentences[l] += findWord(temporary, "noun");
                                    if (!wasAdded) {
                                        wasAdded = true;
                                        for (int m = 0; m < k; m++) {
                                            sentences[l] += ", ";
                                            sentences[l] += findWord(temporary, "noun");
                                        }
                                    }
                                }
                                for (int l = 0; l < i+j; l++) {
                                    if (newConjunctions > 0) {
                                        sentence += sentences[l];
                                        sentence += " ";
                                        sentence += findWord(temporary, "conjunction");
                                        sentence += " ";
                                        sentence += sentences[l+1];
                                        sentence += ". ";
                                        l++;
                                        newConjunctions--;
                                    }
                                    else {
                                        sentence += sentences[l];
                                        sentence += ". ";
                                    }
                                }
                                sentence.pop_back();
                            }
                        }
                    }
                }
            }
        }
        cout << answer << "\n";
        cout << sentence << "\n";
    }    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}