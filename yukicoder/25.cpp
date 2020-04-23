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
    ll p, q;
    cin >> p >> q;
    ll x = __gcd(p, q);
    p /= x; q /= x;
    ll qq = q;
    ll a = 0, b = 0;
    while(qq % 2 == 0 || qq % 5 == 0){
        if(qq%2 == 0) qq /= 2, a++;
        if(qq%5 == 0) qq /= 5, b++;
    }
    if(qq != 1){
        puts("-1");
        return 0;
    }
    while(p % 10 == 0) p /= 10;
    p %= 10;
    while(a < b){
        p = p*2;
        while(p % 10 == 0) p /= 10;
        p %= 10;
        a++;
    }
    while(b < a){
        p = p*5;
        while(p % 10 == 0) p /= 10;
        p %= 10;
        b++;
    }
    cout << p%10 << "\n";
    return 0;
}