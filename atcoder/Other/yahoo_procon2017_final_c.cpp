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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

constexpr int B = 500;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    const int sz = (n+B-1)/B;
    vector<int> laz(sz);
    auto v = make_v(sz, m, 0);
    vector<int> block(n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        block[i] = i/B;
        int x;
        scanf("%d", &x); x %= m;
        v[block[i]][x]++;
        a[i] = x;
    }

    for (int i = 0; i < q; ++i) {
        int l, r, d;
        scanf("%d %d %d", &l, &r, &d); d %= m;
        l--;
        int ans = 0;
        for (int j = l; j < r; ++j) {
            if(l <= B*block[j] && B*(block[j]+1) <= r) {
                (laz[block[j]] += m-d) %= m ;
                ans += v[block[j]][laz[block[j]]];
                j += B-1;
            }else {
                v[block[j]][a[j]]--;
                (a[j] += d) %= m;
                ans += (a[j] == laz[block[j]]);
                v[block[j]][a[j]]++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}