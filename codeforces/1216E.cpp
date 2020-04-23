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
vector<ll> v{0, 45,9045,1395495,189414495,23939649495,2893942449495,339393974949495,38939394344949495,4393939398494949495};
vector<ll> u{0, 9, 189, 2889, 38889, 488889, 5888889, 68888889, 788888889, 8888888889, 98888888889};


int solve2(ll n){
    ll s = 1, b = 1, x = 1;
    for (x = 1; x <= 10; ++x) {
        ll t = b*9*x;
        if(s+t > n) break;
        s += t; b *= 10;
    }
    ll o = (n-s)/x+b, p = (n-s)%x;
    string t = to_string(o);
    return t[p]-'0';
}
int solve(ll x){
    ll p = 9;
    for (int i = 1; i < v.size(); ++i) {
        if(x <= v[i]){
            int keta = i;
            ll y = x-v[i-1];
            ll ok = 0, ng = p;
            while(ng-ok > 1){
                ll mid = (ok+ng)/2;
                ll w = u[i-1]*mid+mid*(1+mid)/2*i;
                if(w < y) ok = mid;
                else ng = mid;
            }
            ll z = y-u[i-1]*ok-ok*(1+ok)/2*i;
            return solve2(z);
        }
        p *= 10;
    }
}
int main() {
    int q;
    cin >> q;
    while(q--){
        ll x;
        scanf("%lld", &x);
        cout << solve(x) << "\n";
    }
    return 0;
}