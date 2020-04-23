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
    long double n, k;
    cin >> n >> k;
    long double ans = n*3-2+6*(k-1)*(n-k);
    ans /= n*n*n;
    printf("%.15Lf\n", ans);
    return 0;
}