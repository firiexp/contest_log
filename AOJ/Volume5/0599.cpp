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
    vector<int> v(n), sum(n+1);
    for (auto &&i : v) scanf("%d", &i);
    sort(v.begin(), v.end(), greater<>());
    for (int i = 0; i < n; ++i) {
        sum[i+1] = sum[i] + v[i];

    }
    vector<int> dp(n+1, INF<int>);
    dp[0] = 0;
    for (int i = 0; i < m; ++i) {
        int c, e;
        cin >> c >> e;
        for (int j = n; j >= 0; --j) {
            chmin(dp[min(j+c, n)], dp[j]+e);
        }
    }
    for (int k = n-1; k >= 0; --k) {
        chmin(dp[k], dp[k+1]);
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        chmax(ans, sum[i]-dp[i]);
    }
    cout << ans << "\n";
    return 0;
}
