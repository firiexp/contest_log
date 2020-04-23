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
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lli", &i);
    ll ans = 0;
    for (int w = 1; w < n; ++w) {
        ll x = 0;
        if((n-1)%w){
            for (int i = 0, j = n-1; i < n-1 && j > 0 && i != j; i += w, j -= w) {
                x += v[i];
                x += v[j];
                if(n-1-i > w) ans = max(ans, x);
            }
        }else {
            for (int i = 0, j = n-1; i < n-1 && j > 0 && i < j; i += w, j -= w) {
                x += v[i];
                x += v[j];
                if(n-1-i > w) ans = max(ans, x);
            }
        }

    }
    cout << ans << "\n";

    return 0;
}