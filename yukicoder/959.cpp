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

int main() {
    ll n, m;
    long double p;
    cin >> n >> m >> p;
    long double ans;
    if(n == 1 && m == 1) ans = p;
    else if(n == 1){
        ans = 2*p*p+(m-2)*p*p*p;
    }else if(m == 1){
        ans = 2*p*p+(n-2)*p*p*p;
    }else {
        ans = 4*p*p*p+2*(n+m-4)*p*p*p*p+(n-2)*(m-2)*p*p*p*p*p;
    }
    printf("%.15Lf\n", ans);
    return 0;
}