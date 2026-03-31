#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using pii = pair<int,int>;
using vi  = vector<int>;
using vl  = vector<ll>;

#define F first
#define S second
#define all(x)     (x).begin(),(x).end()
#define pb        push_back
#define rep(i,a,b) for(int i=(a);i<(b);i++)

const int INF  = 1e9;
const ll  LINF = 1e18;
const int MOD  = 1e9+7;

void modify(vector<int>& a, int i) {
    if (i+1 < static_cast<int>(a.size())) {
        a[i+1] += a[i];
        a.erase(a.begin()+i);

    }
}

void solve() {
    int numberOfTests { 0 };
    cin >> numberOfTests;
    for (int q = 0; q < numberOfTests; q++) {
        int numberOfClasses { 0 };
        cin >> numberOfClasses;
        int answer { 1000000 };
        vector<int> numbers (numberOfClasses);
        vector<int> divisors;

        for (int i = 0; i < numberOfClasses; i++) {
            cin >> numbers[i];
        }
        int sum = reduce(numbers.begin(), numbers.end());
        if (sum > 0) {
            for (int j = 1; j <= sum; j++) {
                if (sum%j == 0) {
                    divisors.push_back(j);
                }
            }
            for (auto& a : divisors) {
                int numberOfOperations { 0 };
                vector<int> temporary = numbers;
                for (int i = 0; i < static_cast<int>(temporary.size()); i++) {
                    while (temporary[i] < a) {
                        modify(temporary, i);
                        numberOfOperations++;
                    }
                    if (temporary[i] > a) {
                        numberOfOperations = 1000000;
                        break;
                    }                    
                }
                answer = min(answer, numberOfOperations);
            }
        }
        else {
            answer = 0;
        }
        cout << answer << "\n";
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}