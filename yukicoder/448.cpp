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
    int n, k;
    cin >> n >> k;
    vector<int> ts(n), ds(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &ts[i], &ds[i]);
    }
    int ng = -1, ok = 1000000000;
    while(ok-ng > 1){
        int mid = (ok+ng)/2;
        int prv = -INF<int>, good = 1;
        for (int i = 0; i < n; ++i) {
            if(mid < ds[i]){
                if(ts[i]-prv < k){
                    good = 0;
                    break;
                }else prv = ts[i];
            }
        }
        (good ? ok : ng) = mid;
    }
    ll ans = accumulate(ds.begin(),ds.end(), 0LL);
    vector<ll> dp(n+1, -INF<ll>); // iで最後に任せたときの任せる仕事の量の最大値
    int cur = 0;
    dp[0] = 0;
    set<ll, greater<>> S;
    S.emplace(0);
    for (int i = 0; i < n; ++i) {
        while(cur < n && ts[cur] + k <= ts[i]){
            if(dp[cur+1] != 0) S.emplace(dp[cur+1]);
            cur++;
        }
        if(ds[i] > ok){ // 必ず任せる
            dp[i+1] = *S.begin() + ds[i];
            cur = i;
            S.clear();
        }else {
            if(!S.empty()){
                dp[i+1] = *S.begin() + ds[i];
            }
        }
    }
    cout << ok << "\n";
    cout << ans-*max_element(dp.begin(),dp.end()) << "\n";
    return 0;
}