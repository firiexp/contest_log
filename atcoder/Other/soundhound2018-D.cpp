#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int h, w;
    cin >> h >> w;
    auto p = make_v(h, w, 0LL); auto f = p;
    for (auto &&i : p) for (auto &&j : i) scanf("%lld", &j);
    for (auto &&i : f) for (auto &&j : i) scanf("%lld", &j);
    auto dp = make_v(2, w, -INF<ll>);
    vector<ll> a(w, 0), b(w, 0);
    dp[0][0] = 0;
    for (int i = 1; i <= h; ++i) {
        int now = i&1, prv = now^1;
        fill(dp[now].begin(), dp[now].end(), -INF<ll>);
        fill(a.begin(), a.end(), 0);
        fill(b.begin(), b.end(), 0);
        for (int j = 1; j < w; ++j) {
            a[j] = max(p[i-1][j-1]-f[i-1][j-1], a[j-1] +p[i-1][j-1]-2*f[i-1][j-1]);
        }
        for (int j = w-2; j >= 0; --j) {
            b[j] = max(p[i-1][j+1]-f[i-1][j+1], b[j+1] +p[i-1][j+1]-2*f[i-1][j+1]);
        }
        ll M = -INF<ll>;
        for (int j = 0; j < w; ++j) {
            M = max({M+p[i-1][j]-f[i-1][j],
                     dp[prv][j]+a[j]+p[i-1][j]-2*f[i-1][j],
                     dp[prv][j]+p[i-1][j]-f[i-1][j]});
            chmax(dp[now][j], M + max(b[j]-f[i-1][j], 0LL));
        }
        reverse(dp[prv].begin(), dp[prv].end());
        reverse(p[i-1].begin(), p[i-1].end());
        reverse(f[i-1].begin(), f[i-1].end());
        fill(a.begin(), a.end(), 0);
        fill(b.begin(), b.end(), 0);
        for (int j = 1; j < w; ++j) {
            a[j] = max(p[i-1][j-1]-f[i-1][j-1], a[j-1] +p[i-1][j-1]-2*f[i-1][j-1]);
        }
        for (int j = w-2; j >= 0; --j) {
            b[j] = max(p[i-1][j+1]-f[i-1][j+1], b[j+1] +p[i-1][j+1]-2*f[i-1][j+1]);
        }
        M = -INF<ll>;
        for (int j = 0; j < w; ++j) {
            M = max({M+p[i-1][j]-f[i-1][j],
                     dp[prv][j]+a[j]+p[i-1][j]-2*f[i-1][j],
                     dp[prv][j]+p[i-1][j]-f[i-1][j]});
            chmax(dp[now][w-j-1], M + max(b[j]-f[i-1][j], 0LL));
        }
    }
    for (int i = 0; i < w; ++i) {
        printf("%lld\n", dp[h&1][i]);
    }
    return 0;
}
