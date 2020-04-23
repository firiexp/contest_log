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
    int c;
    cin >> c;
    vector<array<int, 3>> v(c);
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> v[i][j];
        }
        sort(v[i].begin(), v[i].end());
    }
    int ans = 1;
    for (int i = 0; i < 3; ++i) {
        int m = 1;
        for (int j = 0; j < c; ++j) {
            chmax(m, v[j][i]);
        }
        ans *= m;
    }
    cout << ans << "\n";
    return 0;
}
