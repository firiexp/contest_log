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

template<class T>
vector<T> divisor(T n){
    vector<T> ret;
    for(T i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return(ret);
}

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }
int main() {
    ll n; cin >> n;
    auto v = divisor(n);
    ll ans1 = n-1, ans2 = n-1;
    ll m = v.size();
    auto dp = make_v(m, 4, INF<ll>);
    dp[0][0] = 0;
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < i; ++j) {
            if(v[i]%v[j] != 0) continue;
            for (int k = 1; k <= 3; ++k) {
                if(dp[j][k-1] == INF<ll>) continue;
                chmin(dp[i][k], dp[j][k-1]+v[i]/v[j]-1);
            }
        }
    }
    cout << *min_element(dp.back().begin(),dp.back().end()) << " " << ans2 << "\n";
    return 0;
}