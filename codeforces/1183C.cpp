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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int solve(){
    int k, n, a, b;
    scanf("%d %d %d %d", &k, &n, &a, &b);
    if((k-1)/b < n) return -1;
    ll ok = 0, ng = n+1;
    while(ng - ok > 1){
        ll mid = (ok+ng)/2;
        if(mid*a + (n-mid)*b <k) ok = mid;
        else ng = mid;
    }
    return (int)ok;
}

int main() {
    int q;
    cin >> q;
    while(q--){
        printf("%d\n", solve());
    }
    return 0;
}