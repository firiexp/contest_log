#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int c, n;
    cin >> c >> n;
    vector<vector<bool>> v(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            v[i][j] = s[j]-'0';
        }
    }
    auto dp1 = make_v(n, n/2, 0);
    auto dp2 = make_v(n/2, n, 0);
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n/2; ++j) {
            dp1[i][j] = v[i][j]^v[i][n-j-1];
            cnt1 += dp1[i][j];
        }
    }
    for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < n; ++j) {
            dp2[i][j] = v[i][j]^v[n-i-1][j];
            cnt2 += dp2[i][j];
        }
    }
    int ans = 0;
    if(!cnt1 && !cnt2) ans++;
    for (int _ = 1; _ < c; ++_) {
        int d;
        cin >> d;
        for (int i = 0; i < d; ++i) {
            int y, x;
            cin >> y >> x;
            y--; x--;
            cnt1 -= dp1[y][min(x, n-x-1)];
            dp1[y][min(x, n-x-1)] ^= 1;
            cnt1 += dp1[y][min(x, n-x-1)];
            cnt2 -= dp2[min(y, n-y-1)][x];
            dp2[min(y, n-y-1)][x] ^= 1;
            cnt2 += dp2[min(y, n-y-1)][x];
        }
        if(!cnt1 && !cnt2) ans++;
    }
    cout << ans << "\n";
    return 0;
}