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

template <class T, size_t D> struct _Vec {
    using type = vector<typename _Vec<T, D-1>::type>;
};
template <class T> struct _Vec<T, 1> {
    using type = vector<T>;
};
template<class T, size_t D> using Vec = typename _Vec<T, D>::type;

template <class T>
vector<T> make_v(size_t size, const T& init){ return vector<T>(size, init); }

template<class... Ts>
auto make_v(size_t size, Ts... rest) {
    return vector<decltype(make_v(rest...))>(size, make_v(rest...));
}
int main() {
    int n;
    cin >> n;
    Vec<int, 2> v = make_v(n, 10, 0);
    for (int i = 0; i < 10; ++i) {
        v[0][i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k <= j; ++k) {
                v[i][j] = (v[i][j] + v[i-1][k]) % MOD;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < 10; ++i) {
        ans = (ans + v[n-1][i]) % MOD;
    }
    cout << ans << "\n";
    return 0;
}
