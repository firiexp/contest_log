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

vector<int> get_prime(int n) {
    if(n <= 1) return vector<int>{};
    vector<bool> prime(static_cast<unsigned int>(n + 1), true);
    vector<int> res;
    prime[0] = false; prime[1] = false;
    for(int i = 2; i * i <= n; i++){
        if(prime[i]) for(int j = i << 1; j <= n; j += i) prime[j] = false;
    }
    for (int i = 2; i <= n; ++i) {
        if(prime[i]) res.emplace_back(i);
    }
    return res;
}

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n;
    cin >> n;
    if(n <= 1){
        puts("-1");
        return 0;
    }
    auto v = get_prime(n);
    auto dp = make_v(2, n+1, -1);
    dp[0][0] = 0;
    for (int i = 0; i < v.size(); ++i) {
        int now = i&1, nxt = now^1;
        dp[nxt] = dp[now];
        for (int j = 0; j <= n; ++j) {
            if(j+v[i] > n) break;
            if(dp[now][j] == -1) continue;
            chmax(dp[nxt][j+v[i]], dp[now][j]+1);
        }
    }
    cout << dp[v.size()%2][n] << "\n";
    return 0;
}
