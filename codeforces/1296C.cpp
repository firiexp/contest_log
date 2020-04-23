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

void solve(){
    int n; string s;
    cin >> n >> s;
    vector<int> dy(256), dx(256);
    dy['L'] = 0, dy['R'] = 0, dy['U'] = 1, dy['D'] = -1;
    dx['L'] = -1, dx['R'] = 1, dx['U'] = 0, dx['D'] = 0;
    int ans = INF<int>, ans1 = 0, ans2 = 0;
    vector<int> dp(n+1), dp2(n+1);
    for (int i = 0; i < n; ++i) {
        dp[i+1] = dp[i]+dy[s[i]];
        dp2[i+1] = dp2[i]+dx[s[i]];
    }
    map<pair<int, int>, int> m;
    m[{0, 0}] = 0;
    for (int i = 1; i <= n; ++i) {
        auto x = m.find({dp[i], dp2[i]});
        if(x != m.end()){
            if(i-x->second < ans) {
                ans = i-x->second;
                ans1 = x->second+1, ans2 = i;
            }
        }
        m[{dp[i], dp2[i]}] = i;
    }
    if(ans == INF<int>){
        puts("-1");
    }else {
        printf("%d %d\n", ans1, ans2);
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}