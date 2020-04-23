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


template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ", ";
        os << v[i];
    }
    return os << "}";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "{" << p.first << ", " << p.second << "}";
}

int solve(int n, vector<vector<int>> v){
    int val = 0, cnt = 0;
    for (int i = 0; i < 31 && cnt != n; ++i) {
        int p = cnt;
        for (int j = cnt; j < n; ++j) {
            if(v[j][i]){
                p = j;
                break;
            }
        }
        if(v[p][i] == 0) continue;
        swap(v[cnt], v[p]);
        int x = v[cnt][i];
        cout << v << "\n";
        for (int j = 0; j < 31; ++j) {
            if(j == i) continue;
            if(v[cnt][j]%x) return -1;
            v[cnt][j] /= x;
        }
        for (int j = 0; j < n; ++j) {
            if(cnt == j) continue;
            if(!v[j][i]) continue;
            int y = v[j][i];
            for (int k = 0; k < 31; ++k) {
                v[j][k] -= v[cnt][k]*y;
            }
        }
        cnt++;

    }
    cout << v << "\n";
    vector<int> ans(n);
    return val;
}


int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int val = __builtin_popcount(v[0])%2;
    vector<int> cnt(n);
    cnt[0] = val;
    for (int i = 1; i < n; ++i) {
        cnt[i] = __builtin_popcount(v[i]);
        if(val != cnt[i]%2){
            puts("-1");
            return 0;
        }
    }
    auto dp = make_v(n, 31, 0);
    for (int i = 0; i < n; ++i) {
        int a = v[i], b = v[(i+1)%n];
        for (int j = 0; j < 30; ++j) {
            int p = (a >> j) & 1, q = (b >> j) & 1;
            if(p && !q){
                dp[i][j] = 1;
            }else if(q && !p){
                dp[i][j] = -1;
            }
        }
        dp[i][30] = (cnt[i]-cnt[(i+1)%n])/2;
    }
    cout << dp << "\n";
    cout << solve(n, dp) << "\n";
    return 0;
}