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
    cin >> n;
    vector<int> v(50), u(50);
    v[0] = 1; u[0] = 1;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v[x]++;
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        u[x]++;
    }
    int ans = 0;
    auto dp = make_v(2, 50, 0);
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < i; ++j) {
            if(v[j] && u[i]){
                chmax(dp[0][i], dp[1][j]+1);
                chmax(ans, dp[0][i]);
            }
            if(u[j] && v[i]){
                chmax(dp[1][i], dp[0][j]+1);
                chmax(ans, dp[1][i]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
