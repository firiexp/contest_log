#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    for (auto &&i : a) scanf("%lli", &i);
    for (auto &&i : b) scanf("%lli", &i);
    for (auto &&i : c) scanf("%lli", &i);
    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end(), greater<>());
    sort(c.begin(), c.end(), greater<>());
    vector<ll> ans;
    vector<ll> u;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            u.emplace_back(a[i]+b[j]);
        }
    }
    sort(u.begin(), u.end(), greater<>());
    for (int i = 0; i < min((int)u.size(), k); ++i) {
        for (int j = 0; j < z; ++j) {
            ans.emplace_back(u[i]+c[j]);
        }
    }
    sort(ans.begin(), ans.end(), greater<>());
    for (int i = 0; i < k; ++i) {
        cout << ans[i] << "\n";
    }
    return 0;
}
