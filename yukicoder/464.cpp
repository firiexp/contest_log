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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

vector<int> manacher(const string &s){
    vector<int> res(s.size());
    int i = 0, j = 0;
    while(i < s.size()){
        while(i >= j && i + j < s.size() && s[i-j] == s[i+j]) ++j;
        res[i] = j;
        int k = 1;
        while(i >= k && i + k < s.size() && k + res[i-k] < j) res[i+k] = res[i-k], ++k;
        i += k; j -= k;
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
    string s;
    cin >> s;
    string t;
    for (char i : s) {
        t += i;
        t += '$';
    }
    t.pop_back();
    auto p = manacher(t);
    int n = s.size();
    vector<vector<int>> ps(n, vector<int>(n, 0));
    for (int i = 0; i < t.size(); ++i) {
        int l = i-p[i]+1, r = i+p[i]-1;
        while(l <= r){
            if(t[l] != '$'){
                ps[l/2][r/2] = 1;
            }
            l++, r--;
        }
    }
    auto dp = make_v(4, n+1, 0LL);
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int k = 0; k < 3; ++k) {
            for (int j = 0; j < i; ++j) {
                if(k == 2 || ps[j][i-1]){
                    dp[k+1][i] += dp[k][j];
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if(ps[i][n-1]) ans += dp[3][i];
    }
    cout << ans << "\n";
    return 0;
}