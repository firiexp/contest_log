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
    int n, k, r, s, p;
    cin >> n >> k >> r >> s >> p;
    string t;
    cin >> t;
    vector<string> v(k);
    for (int i = 0; i < n; ++i) {
        v[i%k] += t[i];
    }
    array<int, 3> a{p, r, s};
    array<int, 266> X{};
    X['r'] = 0, X['s'] = 1, X['p'] = 2;
    auto f = [&](string &s) -> int {
        int n = s.size();
        auto dp = make_v(n+1, 3, 0);
        for (int i = 0; i < n; ++i) {
            int val = X[s[i]];
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if(j == k) continue;
                    dp[i+1][k] = max(dp[i+1][k], dp[i][j] + (val == k ? a[k] : 0));
                }
            }
        }
        return *max_element(dp.back().begin(),dp.back().end());
    };
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        if(!v[i].empty()){
            ans += f(v[i]);
        }
    }
    cout << ans << "\n";
    return 0;
}