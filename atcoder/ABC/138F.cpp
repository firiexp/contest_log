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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

string nisin(ll n) {
    string res;
    while (n) {
        if (n & 1) res = "1" + res;
        else res = "0" + res;
        n /= 2;
    }
    return res;
}

int main() {
    ll l, r;
    cin >> l >> r;
    string s = nisin(l), t = nisin(r);
    while(s.size() < t.size()) s = "0" + s;
    while(t.size() < s.size()) t = "0" + t;
    int n = s.size();
    auto dp = make_v(n+1, 2, 2, 2, 2, 0LL);
    dp[0][0][0][0][0] = 1; // dp[cur][l < x][y < r][x < y][zero]
    for (int i = 0; i < n; ++i) {
        for (int a = 0; a < 2; ++a) {
            for (int b = 0; b < 2; ++b) {
                for (int c = 0; c < 2; ++c) {
                    for (int d = 0; d < 2; ++d) {
                        int p = a ? 0 : s[i]-'0';
                        int q = b ? 1 : t[i]-'0';
                        for (int e = p; e <= q; ++e) {
                            for (int f = e; f <= q; ++f) {
                                if(!d && (e ^ f)) continue;
                                (dp[i+1][a || p < e][b || f < q][c || e < f][d || e] += dp[i][a][b][c][d]) %= MOD;
                            }
                        }
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                for (int m = 0; m < 2; ++m) {
                    ans += dp[n][i][j][k][m];
                }
            }
        }
    }
    cout << ans%MOD << "\n";
    return 0;
}