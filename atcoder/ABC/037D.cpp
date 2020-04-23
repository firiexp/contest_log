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
    auto dp = make_v(h+2, w+2, 0);
    auto grid = make_v(h+2, w+2, -1);
    vector<tuple<int, int, int>> g;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            dp[i][j] = 1;
            int a;
            cin >> a;
            g.emplace_back(a, i, j);
            grid[i][j] = a;
        }
    }
    sort(g.begin(), g.end());
    int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
    for (auto &&p : g) {
        int a, i, j;
        tie(a, i, j) = p;
        for (int k = 0; k < 4; ++k) {
            if(grid[i+di[k]][j+dj[k]] > grid[i][j])
                (dp[i+di[k]][j+dj[k]] +=  dp[i][j]) %= MOD;
        }
    }
    int ans = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            (ans += dp[i][j]) %= MOD;
        }
    }
    cout << ans << "\n";
    return 0;
}
