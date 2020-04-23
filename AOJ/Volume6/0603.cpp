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
    int n;
    cin >> n;
    vector<bool> v(n), v2(n-1);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        v[i] = x == 1;
    }
    for (int i = 0; i < n-1; ++i) {
        v2[i] = v[i]^v[i+1];
    }
    int ans = 0, a = 0, b = 0, c = 0;
    for (int i = 0; i < n-1; ++i) {
        if(v2[i]) {
            a++; b++; c++;
        }else {
            c = b+1;
            b = a+1;
            a = 0;
        }
        ans = max({ans, a, b, c});
    }
    cout << ans+1 << "\n";
    return 0;
}
