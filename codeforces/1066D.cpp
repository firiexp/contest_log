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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int l = 0, r = 0, S = 0;
    auto dp = make_v(19, n+1, n);
    while(l < n){
        while(r < n && S+v[r] <= k) S += v[r++];
        dp[0][l] = r;
        S -= v[l++];
    }
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i+1][j] = dp[i][dp[i][j]];
        }
    }
    vector<int> A(n);
    iota(A.begin(),A.end(), 0);
    int x = 0;
    while(m){
        if(m & 1){
            for (int i = 0; i < n; ++i) {
                A[i] = dp[x][A[i]];
            }
        }
        m >>= 1;
        x++;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(A[i] == n) ans = max(ans, A[i]-i);
    }
    cout << ans << "\n";
    return 0;
}