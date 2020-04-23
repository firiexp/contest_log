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
    int t;
    cin >> t;
    while(t--){
        int r, b, k;
        scanf("%d %d %d", &r, &b, &k);
        int g = __gcd(r, b);
        r /= g; b /= g;
        if(r == 1 && b == 1){
            puts("OBEY");
            continue;
        }
        int x = (2*r-1)/b, y = (2*b-1)/r, xx = (r+b-2)/min(r, b);
        if(min(x, y) < k && xx < k) puts("OBEY");
        else puts("REBEL");
    }
    return 0;
}