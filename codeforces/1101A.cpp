#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        ll l, r, d;
        scanf("%lld %lld %lld", &l, &r, &d);
        if(d < l){
            printf("%lld\n", d);
        }else {
            printf("%lld\n", (r+d)/d*d);
        }
    }

    return 0;
}
