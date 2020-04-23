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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int ans = INF<int>;
    for (int i = 0; i < (1 << 2*n); ++i) {
        vector<int> u(n);
        for (int j = 0; j < n; ++j) {
            u[j] = ((i & (1 << (2*j))) != 0) *2+((i & (1 << (2*j+1))) != 0);
        }
        array<int, 3> x{}, y{};
        for (int j = 0; j < n; ++j) {
            if(0 <= u[j] && u[j] <= 2) {
                x[u[j]] += v[j];
                y[u[j]]++;
            }
        }
        if(x[0] != 0 && x[1] != 0 && x[2] != 0){
            chmin(ans, abs(x[0]-a)+abs(x[1]-b)+abs(x[2]-c)+(y[0]+y[1]+y[2]-3)*10);
        }
    }
    cout << ans << "\n";
    return 0;
}
