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
#include <cassert>

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
    int maxa = 0;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i), i--;
    maxa = (*max_element(v.begin(),v.end())) + 1;
    int q;
    cin >> q;
    vector<int> xs(q), ys(q);
    for (int i = 0; i < q; ++i) {
        cin >> xs[i] >> ys[i];
        ys[i]--;
        maxa = max(maxa, ys[i]+1);
    }
    if((ll)(q+1) * n * maxa * maxa > 100000000) assert(0);
    int ans = INF<int>;
    for (int i = 0; i < maxa; ++i) {
        for (int j = i+1; j <= maxa; ++j) {
            int val = 0, val2 = 0;
            for (int k = 0; k < n; ++k) {
                if(v[k] == i){
                    val2 = min(val2+1, val);
                    val++;
                }else if(v[k] ==j){
                    val = min(val+1, val2);
                    val2++;
                }else {
                    val++; val2++;
                }
            }
            ans = min({ans, val, val2});
        }
    }
    cout << ans << "\n";
    for (int qq = 0; qq < q; ++qq) {
        ans = INF<int>;
        v[xs[qq]-1] = ys[qq];
        for (int i = 0; i < maxa; ++i) {
            for (int j = i+1; j < maxa; ++j) {
                int val = 0, val2 = 0;
                for (int k = 0; k < n; ++k) {
                    if(v[k] == i){
                        val2 = min(val2+1, val);
                        val++;
                    }else if(v[k] ==j){
                        val = min(val+1, val2);
                        val2++;
                    }else {
                        val++; val2++;
                    }
                }
                ans = min({ans, val, val2});
            }
        }
        cout << ans << "\n";
    }

    return 0;
}