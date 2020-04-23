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
    long double p, q;
    cin >> p >> q;
    auto v = make_v(4, 3, 0.0L);
    v[0][1] = p, v[0][2] = 1-p;
    for (int i = 0; i < 3; ++i) {
        v[i+1][0] = v[i][1]*q;
        v[i+1][1] = v[i][2];
        v[i+1][2] = (1-q)*v[i][1];
    }
    puts(v[2][0] < v[3][0] ? "YES" :"NO");
    return 0;
}
