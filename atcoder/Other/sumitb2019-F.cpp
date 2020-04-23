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
#include <cassert>

static const int MOD = 1000000007;
using ll = long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    ll x1 = a1-b1, x2 = a2-b2;
    if(t1*x1+t2*x2 == 0){
        puts("infinity");
        return 0;
    }
    if(x1 < 0){
        x1 *= -1; x2 *= -1;
    }
    if(t1*x1+t2*x2 > 0){
        puts("0");
        return 0;
    }
    ll heru = -(t1*x1+t2*x2);
    ll ans = (t1*x1)/heru+(-t2*x2)/heru;
    if(t1*x1%heru == 0) ans--;
    cout << ans << "\n";
    return 0;
}