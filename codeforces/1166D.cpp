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

void solve(ll a, ll b, ll m){
    if(a == b){
        printf("%lld %lld", 1LL, a);
        return;
    }
    for (int i = 2; i <= 50; ++i) {
        ll l = a*(1LL<<(i-2))+i*(i-1)/2, r = a*(1LL<<(i-2))+m*i*(i-1)/2;
        if(r < b) {
            puts("-1");
            return ;
        }
        if(l <= b && b <= r){
            ll amari = b-a*(1LL<<(i-2));
            vector<ll> ans(i, a);
            vector<ll> keisuu(i);
            for (int j = 2; j < i; ++j) {
                ans[j] = ans[j-1]*2;
            }
            for (int j = 1; j < i; ++j) {
                ll y = (1LL << (1LL))
            }
        }
    }

}

int main() {
    int q;
    cin >> q;
    while(q--){
        ll a, b, m;
        scanf("%lld %lld %lld", &a, &b, &m);
        solve(a, b, m);
    }
    return 0;
}