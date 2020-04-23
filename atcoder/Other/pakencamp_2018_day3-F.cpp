#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <cassert>
#include <set>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int q, a, b;
    cin >> q;
    for (int e = 0; e < q; ++e) {
        cin >> a >> b;
        assert(b-a <= 20);
        vector<int> v;
        for (int i = a; i <= b; ++i) {
            v.emplace_back(i);
        }
        int n = static_cast<int>(v.size());
        set<ll> s;
        for (int i = 1; i < (1 << n); ++i) {
            ll x = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1<<j)) {
                    x += v[j];
                }
            }
            s.insert(x);
        }
        cout << s.size() << "\n";
    }
    return 0;
}
