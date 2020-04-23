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
    int n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;
    auto dp = make_v(k+1, n, -INF<int>);
    dp[0][0] = 0;
    vector<vector<int>> G(n);
    array<array<int, 300>, 300> score{};
    score['P']['G'] = x; score['G']['C'] = x; score['C']['P'] = x;
    score['G']['G'] = y; score['C']['C'] = y; score['P']['P'] = y;
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    for (int i = 0; i < n; ++i) {
        G[i].emplace_back(i);
    }
    vector<char> c(n); vector<int> d(k);
    for (auto &&i : c) cin >> i;
    for (auto &&i : d) cin >> i, i--;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            for (auto &&l : G[j]) {
                dp[i+1][l] = max(dp[i+1][l], dp[i][j]+score[c[l]][c[d[i]]]);
            }
        }
    }
    cout << *max_element(dp.back().begin(),dp.back().end()) << "\n";
    return 0;
}