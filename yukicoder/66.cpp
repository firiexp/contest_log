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
    int k;
    cin >> k;
    vector<double> v(1<<k);
    for (auto &&i : v) scanf("%lg", &i);
    auto dp = make_v(k+1, 1<<k, 0.0);
    fill(dp[0].begin(), dp[0].end(), 1.0);
    int mask = (1<<k)-1;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < (1<<k); ++j) {
            int j2 = (j ^ (1<<i)) & mask;
            for (int l = 0; l < (1<<i); ++l) {
                dp[i+1][j] += dp[i][j]*dp[i][j2+l] *(v[j]*v[j])/(v[j]*v[j]+v[j2+l]*v[j2+l]);
            }
        }
        mask ^= (1<<i);
    }
    printf("%.10f\n", dp[k][0]);
    return 0;
}
