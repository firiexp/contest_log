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
    ll n;
    cin >> n;
    ll ok = 0, ng = n+1;
    while(ng - ok > 1){
        ll mid = (ok+ng)/2, x = mid, s = 0;
        while(x != 0){
            s += x;
            x /= 2;
        }
        (s <= n ? ok : ng) = mid;
    }
    ll x = ok, s = 0;
    while(x != 0){
        s += x;
        x /= 2;
    }
    puts(s == n ? "YES" : "NO");
    return 0;
}