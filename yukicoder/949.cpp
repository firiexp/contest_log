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
    vector<int> a(n+1), b(n+1), d(n);
    for (auto &&i : a) scanf("%d", &i);
    for (auto &&j : b) scanf("%d", &j);
    for (auto &&k : d) scanf("%d", &k);
    auto dp = make_v(n+1, n+1, -1);
    sort(d.begin(),d.end());
    dp[0][0] = n;
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; i+j <= n; ++j) {
            int val = a[i]+b[j];
            if(i && dp[i-1][j] >= 0){
                auto x = upper_bound(d.begin(),d.begin()+dp[i-1][j], val);
                dp[i][j] = max<int>(dp[i][j], (x-d.begin())-1);
            }
            if(j && dp[i][j-1] >= 0){
                auto x = upper_bound(d.begin(),d.begin()+dp[i][j-1], val);
                dp[i][j] = max<int>(dp[i][j], (x-d.begin())-1);
            }
            if(dp[i][j] >= 0) ans = max(ans, i+j);
        }
    }
    cout << ans << "\n";
    return 0;
}