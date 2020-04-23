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
int main() {
    int n, m;
    cin >> n >> m;
    m /= 2;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<vector<array<int, 2>>> G(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        G[a].emplace_back(array<int, 2>{b, c});
        G[b].emplace_back(array<int, 2>{a, c});
    }
    vector<int> w(n);
    auto dp = make_v(n, m+1, -INF<int>);
    for (int i = 0; i < n; ++i) {
        dp[i][0] = 0;
    }
    auto dfs = [&](int i, int par, auto &&f) -> void {
        for (int j = 0; j <= m; ++j) {
            dp[i][j] = dp[par][j];
        }
        for (auto &&j : G[i]) {
            if(j[0] != par) {
                w[j[0]] = j[1];
                f(j[0], i, f);
            }
        }
        for (int j = w[i]; j <= m; ++j) {
            dp[par][j] = max(dp[par][j], dp[i][j-w[i]]+v[i]);
        }
    };
    dfs(0, 0, dfs);
    cout << *max_element(dp.front().begin(),dp.front().end()) << "\n";
    return 0;
}