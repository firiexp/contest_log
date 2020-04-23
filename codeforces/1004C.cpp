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

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> cnt(100001);
    vector<int> dp(n+1);
    for (int i = 0; i < n; ++i) {
        dp[i+1] = dp[i] + (cnt[v[i]] == 0);
        cnt[v[i]]++;
    }
    fill(cnt.begin(),cnt.end(), 0);
    ll ans = 0;
    for (int i = n-1; i >= 0; --i) {
        if(cnt[v[i]] == 0) ans += dp[i];
        cnt[v[i]]++;
    }
    cout << ans << "\n";
    return 0;
}