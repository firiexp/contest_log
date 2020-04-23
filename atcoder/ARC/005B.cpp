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
    int x, y, di = 0, dj = 0;
    cin >> y >> x;
    string s;
    cin >> s;
    for (auto &&i : s) {
        if(i == 'U') di = -1;
        else if(i == 'D') di = 1;
        else if(i == 'R') dj = 1;
        else dj = -1;
    }
    auto dp = make_v(11, 11, -1);
    for (int i = 0; i < 9; ++i) {
        cin >> s;
        for (int j = 0; j < 9; ++j) {
            dp[i+1][j+1] = s[j]-'0';
        }
    }
    string ans = to_string(dp[x][y]);
    for (int i = 0; i < 3; ++i) {
        x += di;
        if(dp[x][y] == -1) {
            x -= 2*di;
            di = -di;
        }
        y += dj;
        if(dp[x][y] == -1) {
            y -= 2*dj;
            dj = -dj;
        }
        ans += char(dp[x][y] + '0');
    }
    cout << ans << "\n";
    return 0;
}
