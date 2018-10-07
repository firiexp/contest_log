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
    int n, m;
    cin >> n >> m;
    Vec<int, 2> v = make_v(n, n, INF<int>);
    vector<pair<int,int>> vt;
    for (int i = 0; i < m; ++i) {
        int u, vv, l;
        scanf("%d%d%d", &u, &vv, &l);
        if(u != 1){
            v[u-1][vv-1] = l;
            v[vv-1][u-1] = l;
        }else{
            vt.emplace_back(vv-1, l);
        }
    }
    if(vt.size() < 2){
        cout << -1 << "\n";
        return 0;
    }
    for (int i = 1; i < n; ++i) {
        v[i][i] = 0;
    }
    for (int k = 1; k < n; ++k) {
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                v[i][j] = min(v[i][j], v[i][k]+v[k][j]);
            }
        }
    }
    int ans = INF<int>;
    for (int i = 0; i < vt.size(); ++i) {
        for (int j = i+1; j < vt.size(); ++j) {
            ans = min(ans, vt[i].second+vt[j].second+v[vt[i].first][vt[j].first]);
        }
    }
    cout << (ans < INF<int> ? ans : -1) << "\n";
    return 0;
}
