#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 10007;
using ll = int64_t;
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
    int n; string s;
    cin >> n >> s;
    auto dp = make_v(n+1, 8, 0);
    dp[0][1] = 1;
    for (int i = 0; i < n; ++i) {
        int x = 0;
        if(s[i] == 'O') x = 1;
        if(s[i] == 'I') x = 2;
        for (int j = 0; j < 8; ++j) {
            for (int k = 0; k < 8; ++k) {
                if(!(k & (1 << x))) continue;
                if(!(j&k)) continue;
                (dp[i+1][k] += dp[i][j]) %= MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 8; ++i) {
        (ans += dp[n][i]) %= MOD;
    }
    cout << ans << "\n";
    return 0;
}
