#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> S(1 << n);
    for (int i = 1; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if(i & (1 << j)){
                S[i] = S[i ^ (1 << j)] + v[j];
                break;
            }
        }
    }
    vector<int> dp(1 << n, INF<int>);
    dp[0] = 0;
    for (int i = 1; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if(i & (1 << j)){
                int x = i ^ (1 << j);
                dp[i] = min(dp[i], dp[x]+max(0, v[j]-S[x]%1000));
            }
        }
    }
    cout << dp.back() << "\n";
    return 0;
}