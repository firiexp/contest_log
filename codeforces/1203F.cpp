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

using P = pair<int, int>;

int dp[120][120];

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n, r;
    cin >> n >> r;
    fill_n(dp[0], 120*120, -INF<int>);
    vector<pair<int, int>> posi, nega;
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(b >= 0) posi.emplace_back(a, b);
        else nega.emplace_back(a, b);
    }
    int ans = 0;
    sort(posi.begin(),posi.end());
    for (auto &&i : posi) {
        if(i.first <= r){
            r += i.second;
            ans++;
        }
    }
    sort(nega.begin(),nega.end(), [](P a, P b){ return a.first+a.second > b.first+b.second; });
    dp[0][0] = r;
    int nn = n;
    n = nega.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(dp[i][j] < 0) continue;
            chmax(dp[i+1][j], dp[i][j]);
            if(dp[i][j] >= nega[i].first) chmax(dp[i+1][j+1], dp[i][j]+nega[i].second);
        }
    }
    int ans2 = 0;
    for (int i = 0; i <= n; ++i) {
        if(dp[n][i] >= 0) chmax(ans2, i);
    }
    puts(ans+ans2 == nn ? "YES" : "NO");
    return 0;
}