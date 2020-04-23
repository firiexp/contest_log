#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        printf("%lld\n", (c/2)*(a-b)+(c&1)*a);
    }
    return 0;
}
