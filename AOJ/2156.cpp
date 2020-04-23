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

int main() {
    int n;
    while(cin >> n, n){
        vector<int> mons(n);
        for(auto &&i : mons) cin >> i;
        int maxhp = *max_element(mons.begin(),mons.end());
        vector<pair<int, int>> v, u;
        int m;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            string s, t; int mp, damage;
            cin >> s >> mp >> t >> damage;
            if(t == "All") v.emplace_back(mp, damage);
            else u.emplace_back(mp, damage);
        }
        vector<ll> dp(maxhp+1, MOD), dq(maxhp+1, MOD);
        dp[0] = 0;
        for (int i = 1; i <= maxhp; ++i) {
            for (const auto & j : v){
                dp[i] = min(dp[i], j.first+dp[max(0, i-j.second)]);
            }
        }
        dq[0] = 0;
        for (int i = 1; i <= maxhp; ++i) {
            for (const auto & j : u){
                dq[i] = min(dq[i], j.first+dq[max(0, i-j.second)]);
            }
        }
        for (int k = maxhp-1; k >= 0; --k) {
            dp[k] = min(dp[k], dp[k+1]);
            dq[k] = min(dq[k], dq[k+1]);
        }
        ll ans = INF<ll>/1000;
        for (int i = 0; i <= maxhp; ++i) { // 単体でiまで減らす
            ll x = dp[i];
            for (int j = 0; j < n; ++j) {
                x += dq[max(0, mons[j]-i)];
            }
            ans = min(ans, x);
        }
        cout << ans << "\n";
    }
    return 0;
}