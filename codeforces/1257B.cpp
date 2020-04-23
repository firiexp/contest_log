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
    int t;
    cin >> t;
    while(t--){
        ll x, y;
        scanf("%lld %lld" ,&x, &y);
        if(x == 1){
            puts(y == 1 ? "YES" : "NO");
        }else if(x <= 3){
            puts(y <= 3 ? "YES" : "NO");
        }else {
            puts("YES");
        }
    }
    return 0;
}