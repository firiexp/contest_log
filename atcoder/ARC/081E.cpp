#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

int main() {
    string s;
    cin >> s;
    int n = static_cast<int>(s.size());
    auto nextch = make_v(n+1, 26, n);
    vector<int> dp(n+2, INF<int>);
    vector<pair<char, int>> dp2(n+1, make_pair('a', n));
    dp[n] = 1;
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) nextch[i][j] = nextch[i+1][j];
        nextch[i][s[i]-'a'] = i;
        for (int j = 0; j < 26; ++j) {
            if(nextch[i][j] == n){
                if(dp[i] > 1) dp[i] = 1, dp2[i] = make_pair('a'+j, n);
            }else if (dp[i] > dp[nextch[i][j]+1]+1) {
                dp[i] = dp[nextch[i][j]+1]+1;
                dp2[i] = make_pair('a'+j, nextch[i][j]+1);
            }
        }
    }
    string ans;
    for (int i = 0; i < n;) {
        auto p = dp2[i];
        ans += p.first;
        i = p.second;
    }
    cout << ans << "\n";
    return 0;
}
