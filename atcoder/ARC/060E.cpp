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


int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i);
    v.emplace_back(INF<ll>);
    auto u = make_v(20, n+1, n);
    ll l, q;
    cin >> l >> q;

    for (int i = 0; i < n; ++i) {
        u[0][i] = static_cast<int>(lower_bound(v.begin(), v.end(), v[i] + l+1) - v.begin()-1);
    }
    for (int i = 1; i < 20; ++i) {
        for (int j = 0; j < n; ++j) {
            u[i][j] = u[i-1][u[i-1][j]];
        }
    }
    for (int i = 0; i < q; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(a > b) swap(a, b);
        a--, b--;
        int ng = 0, ok = n+1;
        while(ok-ng > 1){
            int cur = a, mid = (ok+ng)/2;
            for (int j = 0; j < 20; ++j) {
                if(mid & (1<<j)){
                    cur = u[j][cur];
                }
            }
            if(cur >= b) ok = mid;
            else ng = mid;
        }
        printf("%d\n", ok);
    }
    return 0;
}
