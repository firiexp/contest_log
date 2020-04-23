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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&j : v) scanf("%d", &j);
    vector<int> u{4, 8, 15, 16, 23, 42};
    for (int i = 0; i < n; ++i) {
        int k = v[i];
        for (int j = 0; j < 6; ++j) {
            if(u[j] == k) v[i] = j;
        }
    }
    reverse(v.begin(),v.end());
    vector<int> dp(7);
    dp.back() = n;
    for (int i = 0; i < n; ++i) {
        if(dp[v[i]+1]) dp[v[i]+1]--, dp[v[i]]++;
    }
    cout << n-6*dp[0] << "\n";
    return 0;
}