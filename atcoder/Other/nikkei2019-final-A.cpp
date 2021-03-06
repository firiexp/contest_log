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

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n;
    cin >> n;
    vector<ll> v(n), S(n+1);

    ll su = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        su += v[i];
        S[i+1] = su;
    }
    for (int i = 1; i <= n; ++i) {
        ll ans = 0;
        for (int j = 0; j <= n-i; ++j) {
            chmax(ans, S[j+i]-S[j]);
        }
        cout << ans << "\n";
    }
    return 0;
}
