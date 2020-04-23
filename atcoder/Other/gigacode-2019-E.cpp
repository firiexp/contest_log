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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, l;
    cin >> n >> l;
    int v, d;
    cin >> v >> d;
    vector<array<int, 3>> a(n+2);
    a[0] = {0, v, d};
    a[n+1] = {l, 0, 0};
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    sort(a.begin(),a.end());
    vector<double> dp(n+2, INF<int>);
    dp[0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = i+1; j <= n+1; ++j) { // i to j
            if(a[i][2] < a[j][0]-a[i][0]) continue;
            dp[j] = min(dp[j], dp[i]+1.0*(a[j][0]-a[i][0])/a[i][1]);
        }
    }
    if(dp.back() >= INF<int>){
        puts("impossible");
    }else {
        printf("%.10lf\n", dp.back());
    }
    return 0;
}