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
    ll m, k;
    cin >> m >> k;
    ll ans = 1, x = k;
    while(x < m){
        x = x+(2*x+1)*k;
        ans++;
    }
    cout << ans << "\n";
    return 0;
}