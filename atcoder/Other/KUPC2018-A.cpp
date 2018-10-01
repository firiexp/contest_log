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
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i);
    for (int i = 0; i < n; ++i) {
        ll k;
        scanf("%lld", &k);
        v[i] *= k;
    }
    sort(v.begin(), v.end());
    cout << v[n-1] << "\n";
    return 0;
}
