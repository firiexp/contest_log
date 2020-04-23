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
using ll = long long ;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll> v1(a+2, -INF<ll>/100), v2(b+2, -INF<ll>/100);
    for (int i = 0; i < a; ++i) {
        scanf("%lli", &v1[i+1]);
    }
    for (int i = 0; i < b; ++i) {
        scanf("%lli", &v2[i+1]);
    }
    v1[a+1] = INF<ll>/100; v2[b+1] = INF<ll>/100;
    for (int i = 0; i < q; ++i) {
        ll p;
        scanf("%lli", &p);
        int x = static_cast<int>(distance(v1.begin(), lower_bound(v1.begin(), v1.end(), p)));
        int y = static_cast<int>(distance(v2.begin(), lower_bound(v2.begin(), v2.end(), p)));
        ll ans = INF<ll>;
        for (int X = max(x-10, 0); X < min(a+2, x+10); ++X) {
            for (int Y = max(y-10, 0); Y < min(b+2, y+10); ++Y) {
                ll dis1 = p-v1[X], dis2 = p-v2[Y];
                if(((dis1 >= 0) && (dis2 >= 0)) || ((dis1 <= 0 && dis2 <= 0))){
                    chmin(ans, max(llabs(dis1), llabs(dis2)));
                }else {
                    chmin(ans, llabs(dis1)+llabs(dis2)+min(llabs(dis1), llabs(dis2)));
                }
            }
        }
        cout << ans << "\n";
    };
    return 0;
}
