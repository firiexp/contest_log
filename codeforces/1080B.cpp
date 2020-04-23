#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

ll p(ll k){
    if(k < 1) return 0;
    return (k/2)+(k%2)*k*(-1);
}

int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        ll l, r;
        scanf("%lld %lld", &l, &r);
        cout << p(r) - p(l-1) << "\n";
    }
    return 0;
}
