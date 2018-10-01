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

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> v(m+1, 0);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        sum += c;
        v[a-1] += c; v[b] -= c;
    }
    ll k = 0, l = INF<ll>;
    for (int i = 0; i < m; ++i) {
        k += v[i];
        l = min(l, k);
    }
    cout << sum - l << "\n";
    return 0;
}
