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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int w, h;
    cin >> w >> h;
    auto dp = make_v(2, w, 3, INF<ll>);
    ll mi = 0, mi2 = INF<ll>;
    for (int i = 0; i < h; ++i) {
        vector<int> v(w);
        for (auto &&j : v) scanf("%d", &j), j/=10;
        int now = i&1, nxt = now^1;
        for (int j = 0; j < w; ++j) {
            for (int k = 0; k < 3; ++k) {
                dp[nxt][j][k] = INF<ll>;
            }
        }
        for (int j = 0; j < w; ++j) {
            chmin(dp[nxt][j][0], mi+v[j]*10);
            chmin(dp[nxt][j][1], dp[now][j][0]+v[j]*9);
            chmin(dp[nxt][j][2], dp[now][j][1]+v[j]*7);
            chmin(dp[nxt][j][2], dp[now][j][2]+v[j]*7);
            for (int k = 0; k < 3; ++k) {
                chmin(mi2, dp[nxt][j][k]);
            }
        }
        mi = mi2, mi2 = INF<ll>;
    }
    ll ans = INF<ll>;
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < 3; ++j) {
            chmin(ans, dp[h%2][i][j]);
        }
    }
    cout << ans << "\n";
    return 0;
}
