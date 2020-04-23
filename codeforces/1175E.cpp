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
    int n, m;
    cin >> n >> m;
    int M = 500001;
    auto dp = make_v(20, M, -1);
    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        chmax(dp[0][l], r);
    }
    for (int i = 1; i < M; ++i) {
        if(dp[0][i-1] > i) chmax(dp[0][i], dp[0][i-1]);
    }
    for (int i = 1; i < 20; ++i) {
        for (int j = 0; j < M; ++j) {
            if(~dp[i-1][j]) dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
    while(m--){
        int x, y;
        scanf("%d %d", &x, &y);
        int ans = 0;
        for (int i = 19; i >= 0; --i) {
            if(x < dp[i][x] && dp[i][x] < y){
                ans += (1<<i);
                x = dp[i][x];
            }
        }
        if(dp[0][x] >= y){
            printf("%d\n", ans+1);
        }else {
            puts("-1");
        }
    }
    return 0;
}