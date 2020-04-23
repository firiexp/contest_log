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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }
int main() {
    ll h, w, k, v;
    cin >> h >> w >> k >> v;
    auto dp = make_v(h+1, w+1, 0LL);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            scanf("%lld", &dp[i+1][j+1]);
        }
    }
    for (int i = 0; i <= h; ++i) {
        for (int j = 0; j < w; ++j) {
            dp[i][j+1] += dp[i][j];
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j <= w; ++j) {
            dp[i+1][j] += dp[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            for (int l = i+1; l <= h; ++l) {
                for (int m = j+1; m <= w; ++m) {
                    ll val = k*(l-i)*(m-j)+dp[l][m]-dp[i][m]-dp[l][j]+dp[i][j];
                    if(val <= v){
                        ans = max(ans, (l-i)*(m-j));
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}