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
    int t;
    cin >> t;
    while(t--){
        ll n, s;
        scanf("%lld %lld", &n, &s);
        vector<ll> l(n), r(n);
        for (int i = 0; i < n; ++i) {
            scanf("%lld %lld", &l[i], &r[i]);
        }
        ll ok = 1, ng = 1000000010;
        while(ng-ok > 1){
            ll X = (ok+ng)/2;
            ll S = 0;
            int cnt = 0; // Xを超える個数
            vector<ll> v;
            for (int i = 0; i < n; ++i) {
                if(r[i] < X) S += l[i]; // 絶対超えない
                else if(X <= l[i]) { // 何もしなくても超える
                    cnt++;
                    S += l[i];
                }else { // X でようやく超える
                    v.emplace_back(l[i]);
                }
            }
            sort(v.begin(),v.end(), greater<>());
            for (int i = 0; i < v.size(); ++i) {
                if(cnt <= n/2){
                    S += X;
                    cnt++;
                }else {
                    S += v[i];
                }
            }
            if(cnt > n/2 && S <= s) ok = X;
            else ng = X;
        }
        printf("%lld\n", ok);
    }
    return 0;
}