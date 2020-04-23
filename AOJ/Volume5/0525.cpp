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
    int h, w;
    cin >> h >> w;
    auto v = make_v(h, w, 0);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            scanf("%d", &v[i][j]);
        }
    }
    int ans = 0;
    for (int mask = 0; mask < (1<<h); ++mask) {
        int x = 0;
        for (int j = 0; j < w; ++j) {
            int k = 0;
            for (int i = 0; i < h; ++i) {
                k += (v[i][j] ^ ((mask & (1<<i)) != 0));
            }
            x += max(k, h-k);
        }
        chmax(ans, x);
    }
    cout << ans << "\n";
    return 0;
}
