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
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<vector<int>> dp(n+1, vector<int>(26, n));
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) dp[i][j] = dp[i+1][j];
        dp[i][s[i]-'a'] = i;
    }
    double x = 0;
    for (int i = 0; i < n; ++i) {
        int cur = i;
        array<int, 26> cnt{};
        int ans = 1;
        cnt[s[i]-'a']++;
        while(cur < n){
            int m = n, mindex = -1;
            for (int j = 0; j < 26; ++j) {
                if(!cnt[j] && dp[cur+1][j] < m) m = dp[cur+1][j], mindex = j;
            }
            if(~mindex){
                cnt[mindex]++;
            }
            x += ans*(m-cur);
            cur = m;
            ans++;
        }
    }
    printf("%.15f\n", x/n/(n+1)*2);
    return 0;
}