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
using u32 = unsigned;
using u64 = unsigned long long;
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
    auto ok = make_v(n, n, 0);
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ok[i][j] = __gcd(v[i], v[j]) > 1;
        }
    }
    auto dp1 = make_v(n, n, -1), dp2 = dp1;
    for (int i = 0; i < n; ++i) {
        dp1[i][i] = dp2[i][i] = 1;
    }
    auto recl = [&](int l, int r, auto &&f, auto &&g) -> int {
        if(~dp1[l][r]) return dp1[l][r];
        int good = false;
        for (int i = l+1; i <= r; ++i) {
            if(!ok[l][i]) continue;
            if(g(l+1, i, f, g) && f(i, r, f, g)) {
                good = true;
                break;
            }
        }
        return dp1[l][r] = good;
    };
    auto recr = [&](int l, int r, auto &&f, auto &&g) -> int {
        if(~dp2[l][r]) return dp2[l][r];
        int good = false;
        for (int i = l; i <= r-1; ++i) {
            if(!ok[r][i]) continue;
            if(g(l, i, f, g) && f(i, r-1, f, g)) {
                good = true;
                break;
            }
        }
        return dp2[l][r] = good;
    };
    for (int i = 0; i < n; ++i) {
        if(recr(0, i, recl, recr) && recl(i, n-1, recl, recr)){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}