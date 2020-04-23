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
using ll = uint64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;
#pragma GCC optimize ("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%li", &i);
    ll ok = 0, ng = (1ULL<<60)+1;
    vector<vector<int>> vv(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 60; ++j) {
            if(v[i] & (1ULL<<j)) {
                vv[i].emplace_back(j);
            }
        }
    }
    while(ng-ok > 1){
        ll X = (ok+ng)/2;
        ll cnt = n*(n+1)/2;
        int l = 0, r = 0;
        vector<int> x(60);
        ll e = 0;
        while(r < n){
            e |= v[r];
            for (auto &&j : vv[r]) x[j]++;
            r++;
            while(l < r && e >= X){
                for (auto &&j : vv[l]) {
                    x[j]--;
                    if(x[j] == 0) e ^= (1LL<<j);
                }
                l++;
            }
            cnt -= r-l;
        }
        (cnt >= k ? ok : ng) = X;
    }
    cout << ok << "\n";
    return 0;
}