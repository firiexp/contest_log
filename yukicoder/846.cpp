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
    ll p, q, r, a, b, c;
    cin >> p >> q >> r >> a >> b >> c;
    b += a;
    c += b;
    ll lb = max({a*p-p+1, b*q-q+1, c*r-r+1}), ub = min({a*p, b*q, c*r});
    if(lb > ub){
        puts("-1");
        return 0;
    }
    cout << lb << " " << ub << "\n";
    return 0;
}