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
    int n, m;
    cin >> n >> m;
    Vec<int, 2> v = make_v(n, n, INF<int>);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        v[a-1][b-1] = 1;
        v[b-1][a-1] = 1;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                v[i][j] = (i == j ? 0 : min(v[i][j], v[i][k]+v[k][j]));
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        int p = 0;
        for (int j = 0; j < n; ++j) {
            if(v[i][j] == 2) p++;
        }
        cout << p << "\n";
    }
    return 0;
}
