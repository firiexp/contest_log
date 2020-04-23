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
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n, m;
    cin >> n >> m;
    auto v = make_v(n, m, 0);
    for(auto &&i : v) for(auto &&j : i) scanf("%d", &j), j--;
    int ans = INF<int>;
    vector<int> deleted(m, 0);
    for (int i = 0; i < m; ++i) {
        vector<int> cnt(m);
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                if(!deleted[v[j][k]]) {
                    cnt[v[j][k]]++;
                    break;
                }
            }
        }
        chmin(ans, *max_element(cnt.begin(), cnt.end()));
        deleted[max_element(cnt.begin(), cnt.end()) - cnt.begin()] = 1;
    }
    cout << ans << "\n";
    return 0;
}
