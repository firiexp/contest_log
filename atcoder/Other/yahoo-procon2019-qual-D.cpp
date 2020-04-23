#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n;
    cin >> n;
    vector<int> v(n+2);
    for (int i = 0; i < n; ++i) {
        cin >> v[i+1];
    }
    auto dp = make_v(n+3, 5, INF<ll>);
    dp[0][0] = 0;
    for (int i = 0; i < n+2; ++i) {
        for (int j = 0; j < 5; ++j) {
            if(j <= 0) chmin(dp[i+1][0], dp[i][j]+v[i]);
            if(j <= 1) chmin(dp[i+1][1], dp[i][j]+v[i]%2 + 2*(v[i] == 0));
            if(j <= 2) chmin(dp[i+1][2], dp[i][j]+(v[i]+1)%2);
            if(j <= 3) chmin(dp[i+1][3], dp[i][j]+v[i]%2 + 2*(v[i] == 0));
            if(j <= 4) chmin(dp[i+1][4], dp[i][j]+v[i]);
        }
    }
    cout << dp[n+2][4] << "\n";
    return 0;
}
