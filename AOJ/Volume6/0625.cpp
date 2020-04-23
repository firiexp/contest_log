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
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%li", &i);
    vector<ll> dp(n+1, INF<ll>);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        ll l = v[i], r = v[i];
        for (int j = i; j >= max(0, i-m+1); --j) {
            chmin(dp[i+1], dp[j]+(r-l)*(i-j+1)+k);
            if(j) chmax(r, v[j-1]), chmin(l, v[j-1]);
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
