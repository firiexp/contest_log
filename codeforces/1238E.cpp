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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    auto v = make_v(m, m, 0);
    for (int i = 0; i < n-1; ++i) {
        v[s[i]-'a'][s[i+1]-'a']++;
        v[s[i+1]-'a'][s[i]-'a']++;
    }
    vector<ll> dp(1<<m);
    for (int i = 0; i < (1<<m); ++i) {
        for (int j = 0; j < m; ++j) {
            if(i & (1 << j)){
                dp[i] = dp[i ^ (1 << j)];
                for (int k = 0; k < m; ++k) {
                    if(j == k) continue;
                    if(i & (1 << k)) dp[i] -= v[j][k];
                    else dp[i] += v[j][k];
                }
                break;
            }
        }
    }
    vector<ll> ans(1<<m, INF<ll>);
    ans[0] = 0;
    for (int i = 0; i < (1 << m); ++i) {
        for (int j = 0; j < m; ++j) {
            if(i & (1 << j)){
                ans[i] = min(ans[i], ans[i^(1 << j)]);
            }
        }
        ans[i] += dp[i];
    }
    printf("%lld\n", ans.back());
    return 0;
}