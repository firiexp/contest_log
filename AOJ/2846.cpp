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
    ll s, t, d;
    cin >> s >> t >> d;
    vector<ll> v(d);
    for (auto &&i : v) scanf("%lld", &i);
    ll w = accumulate(v.begin(),v.end(), 0LL);
    if(w >= 0){
        for (int i = 0; i < d; ++i) {
            s += v[i];
            if(s <= t){
                cout << i+1 << "\n";
                return 0;
            }
        }
        puts("-1");
        return 0;
    }
    w = -w;
    ll ans = INF<ll>;
    for (ll i = 0; i < d; ++i) {
        if(i) s += v[i-1];
        if(s <= t) ans = min(ans, i);
        else ans = min(ans, i+(s-t+w-1)/w*d);
    }
    if(ans == INF<ll>) return 1;
    cout << ans << "\n";
    return 0;
}