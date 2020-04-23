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
    ll n, m, q;
    cin >> n >> m >> q;
    ll A = n / __gcd(n, m), B = m / __gcd(n, m);
    for (int i = 0; i < q; ++i) {
        ll sx, sy, ex, ey;
        scanf("%lld %lld %lld %lld", &sx, &sy, &ex, &ey);
        sy--; ey--;
        if(sx > ex){
            swap(sx, ex); swap(sy, ey);
        }
        if(sx == 1 && ex == 1){
            if(sy/A == ey/A){
                puts("YES");
            }else {
                puts("NO");
            }
        }else if(sx == 1 && ex == 2){
            if(sy/A == ey/B){
                puts("YES");
            }else {
                puts("NO");
            }
        }else {
            if(sy/B == ey/B){
                puts("YES");
            }else {
                puts("NO");
            }
        }
    }
    return 0;
}