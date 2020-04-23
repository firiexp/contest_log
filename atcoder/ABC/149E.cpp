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
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n), S(n+1);
    for (auto &&i : v) scanf("%lld", &i);
    sort(v.begin(),v.end());
    for (int i = 0; i < n; ++i) {
        S[i+1] = S[i] + v[i];
    }
    ll ng = 0, ok = INF<ll>;
    while(ok - ng > 1){ // X以下である握手値がM個以下であるうちのX
        ll mid = (ok + ng)/2;
        ll val = 0;
        for (int i = 0; i < n; ++i) {
            val += v.end() - lower_bound(v.begin(),v.end(), mid-v[i]);
        }
        if(val <= m) ok = mid;
        else ng = mid;
    }
    ll ans = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        int a = lower_bound(v.begin(),v.end(), ok-v[i]) - v.begin();
        cnt += n-a;
        ans += (S[n] - S[a])+v[i]*(n-a);
    }
    cout << ans + (m-cnt)*(ok-1) << "\n";
    return 0;
}