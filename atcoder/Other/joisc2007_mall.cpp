#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int h, w, a, b;
    cin >> w >> h >> b >> a;
    auto v = make_v(h+1, w+1, (ll)0);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            scanf("%li", &v[i+1][j+1]);
            if(v[i+1][j+1] == -1) v[i+1][j+1] = INF<int>;
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            v[i+1][j] += v[i][j];
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            v[i][j+1] += v[i][j];
        }
    }
    ll ans = INF<ll>;
    for (int i = 0; i < h - a; ++i) {
        for (int j = 0; j < w - b; ++j) {
            chmin(ans, v[i+a][j+b]-v[i][j+b]-v[i+a][j]+v[i][j]);
        }
    }
    cout << ans << "\n";
    return 0;
}
