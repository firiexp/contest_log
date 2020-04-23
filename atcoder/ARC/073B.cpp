#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

template <class T, size_t D> struct _Vec {
    using type = vector<typename _Vec<T, D-1>::type>;
};
template <class T> struct _Vec<T, 1> {
    using type = vector<T>;
};
template<class T, size_t D> using Vec = typename _Vec<T, D>::type;

template <class T>
vector<T> make_v(size_t size, const T& init){ return vector<T>(size, init); }

template<class... Ts>
auto make_v(size_t size, Ts... rest) {
    return vector<decltype(make_v(rest...))>(size, make_v(rest...));
}

int main() {
    int n, w;
    cin >> n >> w;
    vector<vector<ll>> v(4);
    ll a, b;
    cin >> a >> b;
    v[0].emplace_back(b);
    for (int i = 0; i < n-1; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x-a].emplace_back(y);
    }
    for (int i = 0; i < 4; ++i) {
        sort(v[i].begin(), v[i].end(), greater<>());
        partial_sum(v[i].begin(), v[i].end(), v[i].begin());
    }
    ll ans = 0;
    for (int i = 0; i <= v[0].size(); ++i) {
        for (int j = 0; j <= v[1].size(); ++j) {
            for (int k = 0; k <= v[2].size(); ++k) {
                for (int l = 0; l <= v[3].size(); ++l) {
                    if(a*(i+j+k+l)+j+2*k+3*l <= w){
                        ll p = 0;
                        if(i > 0) p += v[0][i-1];
                        if(j > 0) p += v[1][j-1];
                        if(k > 0) p += v[2][k-1];
                        if(l > 0) p += v[3][l-1];
                        ans = max(ans, p);
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
