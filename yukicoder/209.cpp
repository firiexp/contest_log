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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &&i : v) scanf("%d", &i);
        auto dp1 = make_v(n, n, 0);
        auto dp2 = dp1;
        for (int i = 0; i < n; ++i) {
            dp1[i][i] = 1;
            dp2[i][i] = 1;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                for (int k = j+1; k < n; ++k) {
                    if(!dp1[i][j]) continue;
                    if(v[j] < v[k] && v[j] - v[i] < v[k] - v[j]){
                        chmax(dp1[j][k], dp1[i][j]+1);
                    }
                }
            }
        }
        for (int i = n-1; i >= 0; --i) {
            for (int j = i; j >= 0; --j) {
                for (int k = j-1; k >= 0; --k) {
                    if(!dp2[i][j]) continue;
                    if(v[j] < v[k] && v[k] - v[j] > v[j] - v[i] ){
                        chmax(dp2[j][k], dp2[i][j]+1);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int a = 0, b = 0;
            for (int j = 0; j < n; ++j) {
                a = max(a, dp1[j][i]);
                b = max(b, dp2[j][i]);
            }
            ans = max(ans, a+b-1);
        }
        cout << ans << "\n";
    }
    return 0;
}