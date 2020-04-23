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
    vector<int> ls(5001, INF<int>), rs(5001, -INF<int>);
    for (int i = 0; i < n; ++i) {
        ls[v[i]] = min(ls[v[i]], i);
        rs[v[i]] = max(rs[v[i]], i);
    }
    vector<int> cnt(5001);
    vector<vector<pair<int, int>>> a(n);
    for (int i = 0; i < n; ++i) {
        int l = INF<int>, r = -INF<int>, val = 0;
        fill(cnt.begin(),cnt.end(), 0);
        for (int j = i; j < n; ++j) {
            if(!cnt[v[j]]){
                cnt[v[j]] = 1;
                l = min(l, ls[v[j]]); r = max(r, rs[v[j]]);
                val ^= v[j];
            }
            if(l == i && r == j){
                a[l].emplace_back(r, val);
            }
        }
    }
    vector<int> dp(n+1);
    for (int i = 0; i < n; ++i) {
        for (auto &&j : a[i]) {
            dp[j.first+1] = max(dp[j.first+1], dp[i]+j.second);
        }
        dp[i+1] = max(dp[i], dp[i+1]);
    }
    cout << dp.back() << "\n";
    return 0;
}