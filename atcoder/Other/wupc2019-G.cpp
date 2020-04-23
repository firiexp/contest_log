#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;


template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> c(n, vector<ll>(n, 0));
    vector<int> e(n), v(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &v[i]);
    }
    for (int i = m-1; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            c[j][v[i]] += e[j];
        }
        e[v[i]]++;
    }
    vector<ll> dp(1<<n, INF<ll>);
    dp[0] = 0;
    for (int i = 0; i < (1<<n); ++i) {
        for (int j = 0; j < n; ++j) {
            if(i & (1 << j)){
                int k = i^(1<<j);
                ll cost = 0;
                for (int l = 0; l < n; ++l) {
                    if(k & (1<<l)) cost += c[j][l];
                }
                chmin(dp[i], dp[k]+cost);
            }
        }
    }
    cout << dp[(1<<n)-1] << "\n";
    return 0;
}
