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
    ll x, y, z;
    cin >> x >> y >> z;
    ll a = x/z+y/z;
    x %=z, y %= z;
    ll b = 0;
    if(x+y >= z){
        a++;
        b += min(z-y, z-x);
    }
    cout << a << " " << b << "\n";
    return 0;
}