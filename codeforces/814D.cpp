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
    vector<array<ll, 3>> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld %lld", &v[i][1], &v[i][2], &v[i][0]);
    }
    sort(v.begin(),v.end(), greater<>());
    vector<int> dp(n);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if((v[i][1]-v[j][1])*(v[i][1]-v[j][1]) + (v[i][2]-v[j][2])*(v[i][2]-v[j][2]) <= (v[i][0]-v[j][0])*(v[i][0]-v[j][0])){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if(dp[i] == 0 || dp[i]&1){
            ans += v[i][0]*v[i][0];
        }else {
            ans -= v[i][0]*v[i][0];
        }
    }
    printf("%.15Lf", ans*acos(-1.0L));
    cout << ans << "\n";
    return 0;
}