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
    int h, w;
    cin >> h >> w;
    vector<string> v(h);
    for (int i = 0; i < h; ++i) {
        cin >> v[i];
    }
    auto dp = make_v(h+w+1, h+w+1, 0);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            dp[i+j][i-j+w] = v[i][j] == '#';
        }
    }
    int n = h+w+1;
    auto s1 = make_v(n+1, n+1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            s1[i+1][j+1] = dp[i][j];
        }
    }
    auto s2 = s1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            s1[i][j] += s1[i-1][j];
            s2[i][j] += s2[i][j-1];
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(!dp[i][j]) continue;
            for (int k = j+1; k < n; ++k) {
                if(!dp[i][k]) continue;
                if(i-(k-j) >= 0){
                    ans += s2[i-(k-j)+1][k+1]-s2[i-(k-j)+1][j];
                }
                if(i+(k-j) < n){
                    ans += s2[i+(k-j)+1][k+1]-s2[i+(k-j)+1][j];
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(!dp[j][i]) continue;
            for (int k = j+1; k < n; ++k) {
                if(!dp[k][i]) continue;
                if(i-(k-j) >= 0){
                    ans += s1[k][i-(k-j)+1]-s1[j+1][i-(k-j)+1];
                }
                if(i+(k-j) < n){
                    ans += s1[k][i+(k-j)+1]-s1[j+1][i+(k-j)+1];
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}