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
    vector<int> v(2*n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
        v[i+n] = v[i];
    }
    auto dp = make_v(2*n+1, 2*n+1, (ll)0);
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i+len <= 2*n; ++i) {
            if((len&1) == (n&1)){
                chmax(dp[i][i+len], dp[i][i+len-1]+v[(i+len+2*n-1)%(2*n)]);
                chmax(dp[i][i+len], dp[i+1][i+len]+v[i]);
            }else {
                if(v[(i+len+2*n-1)%(2*n)] > v[i]){
                    chmax(dp[i][i+len], dp[i][i+len-1]);
                }else {
                    chmax(dp[i][i+len], dp[i+1][i+len]);
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n; ++i) {
        chmax(ans, dp[i][i+n]);
    }
    cout << ans << "\n";
    return 0;
}
