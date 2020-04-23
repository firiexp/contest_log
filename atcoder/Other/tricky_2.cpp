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
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        if(a < 0){
            a = -a; b = -b; c = -c;
        }
        if(a == 0 && b == 0){
            puts(c == 0 ? "3" : "0");
        }else if(a == 0){
            printf("1 %.15lf\n", -1.0*c/b);
        }else if(1.0L*b*b < 4.0L*a*c) {
            puts("0");
        }else if(abs(1.0L*b*b - 4.0L*a*c) < 1e-5) {
            printf("1 %.15Lf\n", -0.5L*b/a);
        }else if(b > 0){
            printf("2 %.15Lf %.15Lf\n", (-1.0L*b-sqrt(1.0L*b*b-4.0L*a*c))/(2.0L*a), (2.0L*c)/(-1.0L*b-sqrt(1.0L*b*b-4.0L*a*c)));
        }else {
            printf("2 %.15Lf %.15Lf\n", (2.0L*c)/(-1.0L*b+sqrt(1.0L*b*b-4.0L*a*c)), (-1.0L*b+sqrt(1.0L*b*b-4.0L*a*c))/(2.0L*a));
        }
    }
    return 0;
}