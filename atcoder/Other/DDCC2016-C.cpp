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
    int n, k;
    cin >> n >> k;
    map<int, int> v;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        v[__gcd(x, k)]++;
    }
    ll ans = 0;
    for (auto &&i : v) {
        for (auto &&j : v) {
            if(__gcd((ll)i.first*j.first, (ll)k) >= k){
                if(i.first == j.first) ans += (ll)i.second*(i.second-1);
                else ans += (ll)i.second*j.second;
            }
        }
    }
    cout << ans/2 << "\n";
    return 0;
}
