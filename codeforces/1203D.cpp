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
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    t += 'A';
    vector<int> dp(n+1), dq(n+1, m);
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i-1] + (s[i-1] == t[dp[i-1]]);
    }
    t.pop_back();
    reverse(t.begin(),t.end());
    t += 'A';
    for (int i = n-1; i >= 0; --i) {
        dq[i] = dq[i+1] - (s[i] == t[m-dq[i+1]]);
    }
    map<int, int> v;
    for (int i = 0; i <= n; ++i) {
        if(v.count(dq[i])) v[dq[i]] = max(v[dq[i]], i);
        else  v[dq[i]] = i;
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        if(v.count(dp[i])){
            ans = max(ans, v[dp[i]]-i);
        }
    }
    cout << ans << "\n";
    return 0;
}