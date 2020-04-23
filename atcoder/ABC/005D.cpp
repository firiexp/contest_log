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
    int n;
    cin >> n;
    auto v = make_v(n+1, n+1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i+1][j+1];
        }
    }
    vector<int> ans(n*n+1);
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            v[i][j] += v[i][j-1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            v[i][j] += v[i-1][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 1; k <= n; ++k) {
                for (int l = 1; l <= n; ++l) {
                    chmax(ans[(k-i)*(l-j)], v[k][l]-v[k][j]-v[i][l]+v[i][j]);
                }
            }
        }
    }
    for (int i = 0; i < n*n; ++i) {
        chmax(ans[i+1], ans[i]);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        cout << ans[x] << "\n";
    }
    return 0;
}
