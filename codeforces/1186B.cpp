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
    ll n, m;
    cin >> n >> m;
    if(n == 1){
        cout << (m+1)/3 << "\n";
    }else if(n == 2){
        cout << (m+1)/2 << "\n";
    }else {
        ll ans = (m+1)/2;
        ll k = (n-2)/3;
        ans += (m+1)/2*k;
        n -= k*3;
        if(n == 2){
            ans += (m+1)/3;
        }
        cout << ans << "\n";
    }

    return 0;
}