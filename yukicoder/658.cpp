#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 17;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int q;
    cin >> q;
    array<int, 5001> v{};
    v[3] = 1;
    for (int i = 4; i <= 5000; ++i) {
        (v[i] = v[i-1] + v[i-2] + v[i-3] + v[i-4]) %= MOD;
    }
    for (int i = 0; i < q; ++i) {
        ll k;
        scanf("%lld", &k);
        printf("%d\n", v[(k-1)%4912]);
    }
    return 0;
}
