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
    string s, t;
    cin >> s >> t;
    auto dp = make_v(s.size()+1, t.size()+1, 0);
    auto keiro = dp;
    auto n = s.size(), m = t.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(s[i] == t[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
                keiro[i+1][j+1] = 1;
            }
            else {
                if(dp[i][j+1] <= dp[i+1][j]){
                    dp[i+1][j+1] = dp[i+1][j];
                    keiro[i+1][j+1] = 2;
                }else {
                    dp[i+1][j+1] = dp[i][j+1];
                    keiro[i+1][j+1] = 3;
                }
            }
        }
    }
    string ans;
    int a = static_cast<int>(n), b = static_cast<int>(m);
    while(keiro[a][b]){
        if(keiro[a][b] == 1) ans += s[--a], b--;
        else if(keiro[a][b] == 2) b--;
        else if(keiro[a][b] == 3) a--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
    return 0;
}
