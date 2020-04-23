#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <bitset>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<bitset<5050>> dp(n+1), idp(n+1);
    dp[0].set(0);
    for (int i = 0; i < n; ++i) {
        dp[i+1] = dp[i] | (dp[i] << v[i]);
    }
    idp[n].set(0);
    for (int i = n-1; i >= 0; --i) {
        idp[i] = idp[i+1] | (idp[i+1] << v[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int l = max(0, k-v[i]), r = k - 1;
        int c = 0;
        for (int j = l; j <= r; ++j) {
            c += idp[i+1][j]; // l から r に含まれる個数を数える
        }
        bool need = false;
        for (int j = 0; j < k; ++j) { //　尺取りみたいにidpは左に,dpは右にずらしていく
            if(dp[i][j] && c > 0){
                need = true;
                break;
            }
            if (l > 0) {
                c += idp[i+1][--l];
            }

            if (r > 0){
                c -= idp[i+1][--r+1];
            }
        }
        if (not need) ++ans;
    }
    cout << ans << "\n";
    return 0;
}
