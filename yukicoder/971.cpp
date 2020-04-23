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
    int h, w;
    cin >> h >> w;
    auto v = make_v(h+1, w+1, INF<ll>), v2 = make_v(h+1, w+1, INF<ll>);
    v[1][1] = 0; v2[1][1] = 0;
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            if(i == 0 && j == 0) continue;
            v2[i+1][j+1] = min(v2[i+1][j], v2[i][j+1])+1;
            if(s[j] == '.'){
                v[i+1][j+1] = min(v[i+1][j], v[i][j+1])+1;
            }else {
                v[i+1][j+1] = min(v[i+1][j], v[i][j+1])+1+v2[i+1][j+1];
            }
        }
    }
    cout << v[h][w] << "\n";
    return 0;
}