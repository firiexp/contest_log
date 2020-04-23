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
    string s;
    cin >> s;
    int n = s.size();
    ll k;
    cin >> k;
    auto dp = make_v(n+1, 26, 0LL);
    for (int i = n-1; i >= 0; --i) {
        dp[i][s[i]-'a'] = 1;
        if(i == n-1) continue;
        for (int j = 0; j < 26; ++j) {
            if(j != s[i]-'a') dp[i][j] = min(k, dp[i][j]+dp[i+1][j]);
            dp[i][s[i]-'a'] = min(k, dp[i][s[i]-'a']+dp[i+1][j]);
        }
    }
    ll x = 0;
    for (int j = 0; j < 26; ++j) x = min(k, x+dp.front()[j]);
    if(x < k){
        puts("Eel");
        return 0;
    }
    string ans;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            if(dp[i][j] < k) k -= dp[i][j];
            else {
                ans += char('a'+j);
                while(s[i] != j+'a') ++i;
                if(--k <= 0) i = n;
                break;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}