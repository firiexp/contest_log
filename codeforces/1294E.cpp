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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    auto v = make_v(n, m, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &v[i][j]);
            v[i][j]--;
        }
    }
    vector<int> cnt(n);
    for (int j = 0; j < m; ++j) {
        int val = INF<int>;
        fill(cnt.begin(),cnt.end(), n);
        for (int i = 0; i < n; ++i) {
            if(v[i][j]%m == j && (v[i][j]-j)/m < n){
                cnt[((i-(v[i][j]-j)/m)%n+n)%n]--;
            }
        }
        for (int i = 0; i < n; ++i) {
            val = min(val, cnt[i]+i);
        }
        ans += val;
    }
    cout << ans << "\n";
    return 0;
}