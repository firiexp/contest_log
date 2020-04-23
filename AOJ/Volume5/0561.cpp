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
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> v(10);
    for (int i = 0; i < n; ++i) {
        ll x, y;
        scanf("%li %li", &x, &y);
        v[y-1].emplace_back(x);
    }
    for (int i = 0; i < 10; ++i) {
        sort(v[i].begin(), v[i].end());
        v[i].emplace_back(0);
        reverse(v[i].begin(), v[i].end());
        for (int j = 1; j < v[i].size(); ++j) {
            v[i][j] = v[i][j-1]+v[i][j]+2*(j-1);
        }
    }
    vector<ll> dp(1, 0);
    for (auto &&genre : v) {
        vector<ll> newdp(dp.size()+genre.size()+1);
        for (int i = 0; i < dp.size(); ++i) {
            for (int j = 0; j < genre.size(); ++j) {
                chmax(newdp[i+j], dp[i]+genre[j]);
            }
        }
        dp = newdp;
    }
    cout << dp[k] << "\n";
    return 0;
}
