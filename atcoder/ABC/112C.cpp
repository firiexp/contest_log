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

#include <random>

int main() {
    ll n;
    cin >> n;
    vector<ll> x, y, h;
    for (int i = 0; i < n; ++i) {
        ll xx, yy, hh;
        scanf("%lld%lld%lld", &xx, &yy, &hh);
        x.emplace_back(xx);
        y.emplace_back(yy);
        h.emplace_back(hh);
    }
    for(int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            vector<int> v;
            for (int k = 0; k < n; k++) {
                int dist = abs(i - x[k]) + abs(j - y[k]);
                v.emplace_back(h[k] + dist);
            }
            for (auto &item : v) {
                bool p = true;
                for (int k = 0; k < n; k++) {
                    int dist = abs(i - x[k]) + abs(j - y[k]);
                    if (max(item - dist, 0) != h[k]) p = false;
                }
                if (p) {
                    cout << i << " " << j << " " << item << "\n";
                    return 0;
                }
            }
        }
    }
    return 0;
}
