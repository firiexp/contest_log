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
    int a, b, c;
    cin >> a >> b >> c;

    int n = a+b+c;
    vector<int> v(n);
    for (int i = 0; i < a; ++i) {
        int x;
        scanf("%d", &x);
        v[x-1] = 0;
    }
    for (int i = 0; i < b; ++i) {
        int x;
        scanf("%d", &x);
        v[x-1] = 1;
    }
    for (int i = 0; i < c; ++i) {
        int x;
        scanf("%d", &x);
        v[x-1] = 2;
    }
    auto dp = make_v(n+1, 3, INF<int>);
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = j; k < 3; ++k) {
                chmin(dp[i+1][k], dp[i][j]+(v[i] != k));
            }
        }
    }
    cout << *min_element(dp.back().begin(),dp.back().end()) << "\n";
    return 0;
}