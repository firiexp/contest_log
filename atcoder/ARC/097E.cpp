#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
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


int main() {
    int n;
    cin >> n;
    auto black = make_v(n, n+1, 0);
    auto white = make_v(n, n+1, 0);
    vector<int> b(n, 0), w(n, 0), sumb(n+1, 0), sumw(n+1, 0);
    for (int i = 0; i < 2*n; ++i) {
        char c; int a;
        cin >> c >> a;
        partial_sum(b.rbegin(), b.rend(), sumb.rbegin()+1);
        partial_sum(w.rbegin(), w.rend(), sumw.rbegin()+1);
        for (int j = n; j >= 0; --j) {
            if(c == 'B') black[a-1][j] = sumw[j] + sumb[a];
            if(c == 'W') white[a-1][j] = sumw[a] + sumb[j];
        }
        if(c == 'B') b[a-1]++;
        else w[a-1]++;
    }
    auto dp = make_v(n+1, n+1, INF<int>);
    dp[0][0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if(i < n) dp[i+1][j] = min(dp[i+1][j], dp[i][j] + black[i][j]);
            if(j < n) dp[i][j+1] = min(dp[i][j+1], dp[i][j] + white[j][i]);
        }
    }
    cout << dp[n][n] << "\n";
    return 0;
}
