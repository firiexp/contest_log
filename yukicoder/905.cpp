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
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i);
    vector<int> a(n), b(n);
    for (int i = 0; i < n-1; ++i) {
        a[i+1] = a[i] + (v[i] <= v[i+1]);
        b[i+1] = b[i] + (v[i] >= v[i+1]);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d %d\n", a[r]-a[l] == r-l, b[r]-b[l] == r-l);
    }
    return 0;
}