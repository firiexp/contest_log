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


template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ", ";
        os << v[i];
    }
    return os << "}";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "{" << p.first << ", " << p.second << "}";
}


template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n, d, x, y;
    cin >> n >> d >> x >> y;
    x = abs(x), y = abs(y);
    if(x%d || y%d) {
        puts("0");
        return 0;
    }
    x /= d, y /= d;
    auto comb = make_v(n+1, n+1, 0.0L);
    cout << setprecision(15);
    comb[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        comb[i][0] = comb[i-1][0]/2;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            comb[i][j] = (comb[i-1][j] + comb[i-1][j-1])/2;
            if(i < j) comb[i][j] = 0;
        }
    }
    long double ans = 0;
    for (int p = 0; p <= n; ++p) {
        if(p < x || n-p < y || p%2 != x%2 || (n-p)%2 != y%2) continue;
        ans += comb[n][p] * comb[p][(p-x)/2]*comb[n-p][(n-p-y)/2];
    }
    cout << ans << "\n";
    return 0;
}