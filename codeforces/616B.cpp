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
    int n, m;
    cin >> n >> m;
    auto v = make_v(n, m, 0);
    vector<int> streets(n);
    for (int i = 0; i < n; ++i) {
        int x = INF<int>;
        for (int j = 0; j < m; ++j) {
            int k;
            cin >> k;
            x = min(x, k);
            v[i][j] = k;
        }
        streets[i] = x;
    }
    int dis = static_cast<int>(max_element(streets.begin(), streets.end()) - streets.begin());
    cout << *min_element(v[dis].begin(), v[dis].end()) << "\n";
    return 0;
}
