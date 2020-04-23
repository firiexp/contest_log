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
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        if(s[i] == 'o') a.emplace_back(i);
    }
    int m = a.size();
    vector<int> dp(m);
    int val = 1, cur = 0;
    map<int, int> x, y;
    for (int i = 0; i < m; ++i) {

        while(a[cur] < a[i]-c) val = max(val, dp[cur++]+1);
        dp[i] = val;
        if(dp[i] > k) return 0;
        if(!x.count(dp[i])) x[dp[i]] = i;
    }
    vector<int> dp2(m);
    val = 1, cur = m-1;
    for (int i = m-1; i >= 0; --i) {
        while(a[cur] > a[i]+c) val =  max(val, dp2[cur--]+1);
        dp2[i] = val;
        if(!y.count(dp2[i])) y[dp2[i]] = i;
    }
    for (int i = 0; i < m; ++i) {
        if(x[dp[i]] == y[dp2[i]] && x[dp[i]] == i) cout << a[i]+1 << "\n";
    }
    return 0;
}