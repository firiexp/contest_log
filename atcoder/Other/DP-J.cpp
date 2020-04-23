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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }


int main() {
    int n;
    cin >> n;
    vector<int> v(3, 0);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        v[a-1]++;
    }
    long double p = 1.0/n;
    auto dp = make_v(n+1, n+1, n+1, 0.0L);
    for (int k = 0; k <= n; ++k) {
        for (int j = 0; j <= n; ++j) {
            for (int i = 0; i <= n; ++i) {
                if(i+j+k == 0 || i+j+k > n) continue;
                if(i) dp[i][j][k] += dp[i-1][j][k]*i*p;
                if(j) dp[i][j][k] += dp[i+1][j-1][k]*j*p;
                if(k) dp[i][j][k] += dp[i][j+1][k-1]*k*p;
                dp[i][j][k] = (dp[i][j][k]+1)/(1-(n-i-j-k)*p);
            }
        }
    }
    cout << setprecision(15) << dp[v[0]][v[1]][v[2]] << "\n";
    return 0;
}
