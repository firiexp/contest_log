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
    int h, w;
    cin >> h >> w;
    int h2 = h/2, w2 = w/2;
    int a, b;
    cin >> a >> b;
    ll ans = 0;
    auto v = make_v(h, w, false);
    int cnt = 0;
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            v[i][j] = (s[j] == 'S');
            cnt += v[i][j];
        }
    }
    {
        auto u = v;
        ll x = 0;
        for (int i = 0; i < h2; ++i) {
            for (int j = 0; j < w; ++j) {
                if(u[i][j] + u[h-i-1][j] == 1) u[i][j] = u[h-i-1][j] = false, x = 1;
            }
        }
        ll c = 0;
        for (int i = 0; i < h2; ++i) {
            for (int j = 0; j < w2; ++j) {
                if (u[i][j] + u[i][w-j-1] == 1) c++, u[i][j] = u[h-i-1][j] = false;
            }
        }
        chmax(ans, (c+x)*a+b*(x != 0 || c != 0));
    }
    ll x = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w2; ++j) {
            if(v[i][j] + v[i][w-j-1] == 1) v[i][j] = v[i][w-j-1] = false, x = 1;
        }
    }
    ll c = 0;
    for (int i = 0; i < h2; ++i) {
        for (int j = 0; j < w2; ++j) {
            if (v[i][j] + v[h-i-1][j] == 1) c++, v[i][j] = v[h-i-1][j] = false;
        }
    }
    chmax(ans, (c+x)*b+a*(x != 0 || c != 0));
    for (int i = 0; i < h2; ++i) {
        for (int j = 0; j < w2; ++j) {
            if(v[i][j]) ans += max(2*a+b, 2*b+a);
        }
    }
    cout << ans << "\n";
    return 0;
}
