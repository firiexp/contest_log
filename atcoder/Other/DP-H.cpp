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
    int h, w;
    cin >> h >> w;
    auto dp = make_v(h, w, 0);
    dp[0][0] = 1;
    vector<string> v(h);
    for (int i = 0; i < h; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(v[i][j] == '#') continue;
            if(i != 0) (dp[i][j] += dp[i-1][j]) %= MOD;
            if(j != 0) (dp[i][j] += dp[i][j-1]) %= MOD;
        }
    }
    cout << dp[h-1][w-1] << "\n";
    return 0;
}
