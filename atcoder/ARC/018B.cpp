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
    using P = pair<ll, ll>;
    vector<P> v(n);
    for (int i = 0; i < n; ++i) {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        v[i] = make_pair(x, y);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            for (int k = j+1; k < n; ++k) {
                auto a = v[i], b = v[j], c = v[k];
                ll p = llabs(
                        (a.second-c.second)*(b.first-c.first)
                        -(a.first-c.first)*(b.second-c.second));
                if(p%2 == 0 && p != 0) ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
