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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for(auto &&i : v) for(auto &&j : i) scanf("%d", &j);
    vector<ll> dp(1<<n), dq(1<<n);
    for (int i = 1; i < (1<<n); ++i) {
        for (int j = 0; j < n; ++j) {
            if(i & (1 << j)){
                int a = i ^ (1 << j);
                dp[i] = dp[a];
                for (int k = 0; k < n; ++k) {
                    if(a & (1 << k)){
                        dp[i] += v[j][k];
                    }
                }
                break;
            }
        }
    }
    for (int i = 1; i < (1 << n); ++i) {
        dq[i] = dp[i];
        for (int j = (i-1)&i; j != i; j = (j-1)&i) {
            dq[i] = max(dq[i], dq[i^j]+dp[j]);
        }
    }
    cout << dq.back() << "\n";
    return 0;
}