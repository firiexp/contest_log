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
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i);
    ll min1 = INF<int>, min2 = INF<int>, S = 0, T = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if(!(i&1)) min1 = min(min1, v[i]);
        min2 = min(min2, v[i]);
    }
    int q;
    cin >> q;
    while(q--){
        int t;
        scanf("%d", &t);
        if(t == 1){
            int x, a;
            scanf("%d %d", &x, &a);
            x--;
            ll val = v[x]-T-(!(x&1) ? S : 0);
            if(val >= a){
                v[x] -= a;
                if(!(x&1)){
                    min1 = min(min1, val-a);
                }
                min2 = min(min2, val-a);
                ans += a;
            }
        }else if(t == 2){
            int a;
            scanf("%d", &a);
            if(min1 >= a){
                ans += (n+1)/2*a;
                min1 -= a;
                min2 = min(min1, min2);
                S += a;
            }
        }else {
            int a;
            scanf("%d", &a);
            if(min2 >= a){
                ans += n*a;
                min2 -= a;
                min1 -= a;
                T += a;
            }
        }

    }
    cout << ans << "\n";
    return 0;
}