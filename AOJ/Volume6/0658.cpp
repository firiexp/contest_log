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
using u32 = uint32_t;
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
    vector<string> v(h);
    for (auto &&i : v) cin >> i;
    ll ans = 0;
    auto O = make_v(h, w, 0); auto I = O;
    for (int i = 0; i < h; ++i) {
        for (int j = w-1; j >= 0; --j) {
            if(j != w-1) O[i][j] += O[i][j+1];
            O[i][j] += v[i][j] == 'O';
        }

    }
    for (int i = h-1; i >= 0; --i) {
        for (int j = 0; j < w; ++j) {
            if(i != h-1) I[i][j] += I[i+1][j];
            I[i][j] += v[i][j] == 'I';
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(v[i][j] == 'J') ans += O[i][j] * I[i][j];
        }
    }
    cout << ans << "\n";
    return 0;
}
