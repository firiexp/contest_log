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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n;
    cin >> n;
    auto v = make_v(2, n, 0);
    auto dp = make_v(2, n+1, 0LL);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &v[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            chmax(dp[j][i+1], dp[j][i]);
            chmax(dp[j^1][i+1], dp[j][i]+v[j][i]);
        }
    }
    cout << max(dp[0].back(), dp[1].back()) << "\n";
    return 0;
}