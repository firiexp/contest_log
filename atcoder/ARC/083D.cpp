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

template <class T>
vector<T> make_v(size_t size, const T& init){ return vector<T>(size, init); }

template<class... Ts>
auto make_v(size_t size, Ts... rest) { return vector<decltype(make_v(rest...))>(size, make_v(rest...)); }


int main() {
    int n;
    cin >> n;
    auto v = make_v(n, n, 0LL);
    auto x = make_v(n, n, 1);
    for (auto &&i : v) {
        for (auto &&j : i) {
            scanf("%lld", &j);
        }
    }
    ll ans = 0;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(i == k || k == j || j == i) continue;
                if(v[i][j] > v[i][k]+v[k][j]){
                    puts("-1");
                    return 0;
                }else if(v[i][j] == v[i][k]+v[k][j]){
                    x[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if(x[i][j]) ans += v[i][j];
        }
    }
    cout << ans << "\n";
    return 0;
}
