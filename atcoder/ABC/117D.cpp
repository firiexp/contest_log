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


int main() {
    ll n, k;
    cin >> n >> k;
    vector<int> u(41, 0);
    for (int i = 0; i < n; ++i) {
        ll tmp;
        cin >> tmp;
        for (int j = 0; j < 41; ++j) {
            u[40-j] += ((tmp >> j) & 1);
        }
    }
    int p = 41;
    string s;
    for (int i = 0; i < p; ++i) {
        s += (char)('0' + (k >> i & 1));
    }
    reverse(s.begin(), s.end());
    auto dp = make_v(p+1, 2, -1LL);
    dp[0][0] = 0;
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < 2; ++j) {
            if(dp[i][j] < 0) continue;
            int x = j ? 1 : s[i] - '0';
            for (int d = 0; d <= x; ++d) {
                ll y = (1LL << (p-i-1));
                ll tmp = (d == 0 ? u[i] : n-u[i])*y;
                dp[i+1][j || d < x] = max(dp[i+1][j || d < x], dp[i][j] + tmp);
            }
        }
    }
    cout << max(dp[p][0], dp[p][1]) << "\n";
    return 0;
}
