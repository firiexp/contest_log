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
    int n;
    cin >> n;
    auto v = make_v(n, n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            cin >> v[i][j];
            v[j][i] = v[i][j];
        }
    }
    vector<int> dp1(1<<n);
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if(i & (1 << j)){
                dp1[i] = dp1[i^(1 << j)];
                for (int k = 0; k < n; ++k) {
                    if(i & (1 << k)) dp1[i] += v[j][k];
                }
                break;
            }
        }
    }
    int ans = dp1.back();
    int mask = (1 << n)-1;
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = (i-1)&i; j != i; j = (j-1)&i) {
            ans = max(ans, dp1[mask^i]+dp1[j]+dp1[j^i]);
        }
    }
    cout << ans << "\n";
    return 0;
}