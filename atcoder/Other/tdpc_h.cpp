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
    int n, w, c;
    cin >> n >> w >> c;
    vector<vector<pair<int, int>>> A(50);
    for (int i = 0; i < n; ++i) {
        int a, b, C;
        cin >> a >> b >> C;
        A[C-1].emplace_back(a, b);
    }
    auto dp = make_v(2, c+1, w+1, -INF<int>);
    dp[0][0][0] = 0;
    for (int col = 0; col < 50; ++col) {
        if(!A[col].empty()){
            for (auto &&e : A[col]) {
                for (int i = 1; i >= 0; --i) {
                    for (int j = 0; j <= c-(!i); ++j) {
                        for (int k = w - e.first; k >= 0; --k) {
                            chmax(dp[1][j+(!i)][k+e.first], dp[i][j][k]+e.second);
                        }
                    }
                }
            }
            for (int j = 0; j <= c; ++j) {
                for (int k = 0; k <= w; ++k) {
                    chmax(dp[0][j][k], dp[1][j][k]);
                    dp[1][j][k] = -INF<int>;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j <= c; ++j) {
            for (int k = 0; k <= w; ++k) {
                chmax(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}