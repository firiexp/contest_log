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
    int n, l, h;
    cin >> n >> l >> h;
    l--;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<ll> val(1 << n, 1);
    vector<int> cnt(1 << n);
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if(i & (1 << j)){
                int x = i ^ (1 << j);
                cnt[i] = cnt[x]+1;
                val[i] = val[x]/__gcd<ll>(val[x], v[j])*v[j];
                if(val[i] > h) val[i] = h+1;
                break;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i < (1 << n); ++i) {
        if(cnt[i]&1) ans += cnt[i]*(h/val[i]-l/val[i]);
        else ans -= cnt[i]*(h/val[i]-l/val[i]);
    }
    cout << ans << "\n";
    return 0;
}