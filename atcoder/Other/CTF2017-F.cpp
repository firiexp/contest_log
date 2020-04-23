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

template <class T>
vector<T> make_v(size_t size, const T& init){ return vector<T>(size, init); }

template<class... Ts>
auto make_v(size_t size, Ts... rest) { return vector<decltype(make_v(rest...))>(size, make_v(rest...)); }

template <class T>
T pow_ (T x, T n, T M){
    uint64_t u = 1, xx = x;
    while (n > 0){
        if (n&1) u = u * xx % M;
        xx = xx * xx % M;
        n >>= 1;
    }
    return static_cast<T>(u);
};

int main() {
    int n, k;
    cin >> n >> k;
    map<int, int> m;
    int mx = k;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        m[a]++;
        mx = max(mx, a);
    }
    u32 sz = 1;
    while(sz <= mx) sz <<= 1;
    auto v = make_v(2, sz, 0LL);
    v[0][0] = 1;
    int i = 0;
    for (auto &&x : m) {
        int now = i&1, nxt = now^1;
        fill(v[nxt].begin(), v[nxt].end(), 0);
        for (int j = 0; j < sz; ++j) {
            (v[nxt][j] += v[now][j]*pow_(2, x.second-1, MOD)) %= MOD;
            (v[nxt][j^x.first] += v[now][j]*pow_(2, x.second-1, MOD)) %= MOD;
        }
        i++;
    }
    cout << v[i&1][k] << "\n";
    return 0;
}
