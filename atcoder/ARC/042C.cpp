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
    int n, p;
    cin >> n >> p;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &v[i].first, &v[i].second);
    }
    sort(v.begin(),v.end(), greater<>());
    auto dp = make_v(n+1, p+2, -INF<int>);
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= p+1; ++j) {
            if(j != p+1) chmax(dp[i+1][min(j+v[i].first, p+1)], dp[i][j] + v[i].second);
            chmax(dp[i+1][j], dp[i][j]);
        }
    }
    cout << *max_element(dp[n].begin(),dp[n].end()) << "\n";
    return 0;
}