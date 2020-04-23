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

ll solve(){
    ll n, m;
    scanf("%lld %lld", &n, &m);
    ll p = (n-m)/(m+1);
    ll ans = p*(p+1)/2*(m+1)+(n-m-p*(m+1))*(p+1);
    return n*(n+1)/2-ans;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        printf("%lld\n", solve());
    }
    return 0;
}