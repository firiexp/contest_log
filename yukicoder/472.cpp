#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T>
vector<T> make_v(size_t size, const T& init){ return vector<T>(size, init); }

template<class... Ts>
auto make_v(size_t size, Ts... rest) { return vector<decltype(make_v(rest...))>(size, make_v(rest...)); }




int main() {
    int n, p;
    cin >> n >> p;
    auto dp = make_v(2, p+1, INF<int>);
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int now = i%2, nxt = (i+1)%2;
        fill(dp[nxt].begin(), dp[nxt].end(), INF<int>);
        vector<int> v{0, 0, 0, 1};
        scanf("%d %d %d", &v[0], &v[1], &v[2]);
        for (int j = 0; j <= p; ++j) {
            for (int k = 0; k <= 3; ++k) {
                if(j+k <= p) dp[nxt][j+k] = min(dp[nxt][j+k], dp[now][j]+v[k]);
            }
        }
    }
    cout << setprecision(15) << (long double)dp[(n%2)][p]/n << "\n";
    return 0;
}
