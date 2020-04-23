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
    int n, l, r;
    cin >> n >> l >> r;
    l--;
    auto dp = make_v(n+1, 3, 0LL);
    dp[0][0] = 1;
    auto f = [](int x, int y){ return x/3+(x%3 > (y+2)%3); };
    vector<int> v{ f(r, 0)-f(l, 0),
                   f(r, 1)-f(l, 1),
                   f(r, 2)-f(l, 2)};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                (dp[i+1][(j+k)%3] += dp[i][j]*v[k]) %= MOD;
            }
        }
    }
    cout << dp.back()[0] << "\n";
    return 0;
}