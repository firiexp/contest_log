#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
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
    int n, d;
    cin >> n >> d;
    auto v = make_v(n, d, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            cin >> v[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int s = 0;
            for (int k = 0; k < d; ++k) {
                s += (v[i][k]-v[j][k])*(v[i][k]-v[j][k]);
            }
            int ok = 0;
            for (int l = 0; l < 5000; ++l) {
                if(l*l == s) ok++;
            }
            if(ok) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}