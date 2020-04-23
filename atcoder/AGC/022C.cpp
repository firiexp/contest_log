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

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.first << "," << p.second << ")";
}

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ",";
        os << v[i];
    }
    return os << "}";
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &&i : a) scanf("%d", &i);
    for (auto &&i : b) scanf("%d", &i);
    set<int> used;
    for (int i = 1; i <= 50; ++i) {
        used.insert(i);
    }
    {
        auto dp = make_v(51, 51, 0);
        for (int i = 0; i <= 50; ++i) {
            dp[i][i] = 1;
            for (auto &&j : used) {
                dp[i][i%j] = 1;
            }
        }
        for (int z = 0; z <= 50; ++z) {
            for (int x = 0; x <= 50; ++x) {
                for (int y = 0; y <= 50; ++y) {
                    if(dp[x][z] && dp[z][y]) dp[x][y] = 1;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if(!dp[a[i]][b[i]]){
                puts("-1");
                return 0;
            }
        }
    }
    for (int k = 50; k >= 1; --k) {
        auto dp = make_v(51, 51, 0);
        used.erase(k);
        for (int i = 0; i <= 50; ++i) {
            dp[i][i] = 1;
            for (auto &&j : used) {
                dp[i][i%j] = 1;
            }
        }
        for (int z = 0; z <= 50; ++z) {
            for (int x = 0; x <= 50; ++x) {
                for (int y = 0; y <= 50; ++y) {
                    if(dp[x][z] && dp[z][y]) dp[x][y] = 1;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if(!dp[a[i]][b[i]]){
                used.insert(k);
            }
        }
    }
    ll ans = 0;
    for (auto &&i : used) {
        ans += (1LL << i);
    }
    cout << ans << "\n";
    return 0;
}
