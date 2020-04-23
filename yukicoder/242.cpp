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
    int n;
    cin >> n;
    if(n < 5){
        puts("0");
        return 0;
    }
    double ans = log(12);
    for (int i = 0; i < n; ++i) {
        ans += log(i+1)-log(99-i);
    }
    for (int i = 0; i < n-5; ++i) {
        ans += log(94-i)-log(i+1);
    }
    printf("%.10lf\n", exp(ans));
    return 0;
}