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
    int n, q;
    cin >> n >> q;
    vector<int> z;
    vector<int> l(n), r(n), x(q), y(q);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &l[i], &r[i]);
        z.emplace_back(l[i]);
        z.emplace_back(r[i]);
    }
    for (int i = 0; i < q; ++i) {
        scanf("%d %d", &x[i], &y[i]);
        z.emplace_back(x[i]);
        z.emplace_back(y[i]);
    }
    sort(z.begin(), z.end());
    z.erase(unique(z.begin(), z.end()), z.end());
    for (int i = 0; i < n; ++i) {
        l[i] = (lower_bound(z.begin(),z.end(), l[i])-z.begin());
        r[i] = (lower_bound(z.begin(),z.end(), r[i])-z.begin());
    }
    for (int i = 0; i < q; ++i) {
        x[i] = (lower_bound(z.begin(),z.end(), x[i])-z.begin());
        y[i] = (lower_bound(z.begin(),z.end(), y[i])-z.begin());
    }
    z.emplace_back(MOD);
    z.emplace_back(-MOD);
    int M = z.size();
    auto dp = make_v(18, M, -1);
    for (int i = 0; i < n; ++i) {
        dp[0][l[i]] = r[i];
    }
    for (int j = M-2; j >= 0; --j) {
        if(!(~dp[0][j])) dp[0][j] = dp[0][j+1];
        else if(~dp[0][j+1]) dp[0][j] = min(dp[0][j], dp[0][j+1]);
    }
    for (int i = 1; i < 18; ++i) {
        for (int j = 0; j < M; ++j) {
            if(~dp[i-1][j]) dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
    for (int i = 0; i < q; ++i) {
        int s = x[i], t = y[i];
        int ans = 0;
        for (int j = 17; j >= 0; --j) {
            if(s < dp[j][s] && dp[j][s] <= t){
                ans += (1<<j);
                s = dp[j][s];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}