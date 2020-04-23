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
    auto v = make_v(4, 4, 0);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> v[i][j];
        }
    }
    vector<int> cnt(4);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            cnt[(i-j+3)%4] += v[i][j];
            cnt[i] += v[i][j];
        }
    }
    for (int i = 0; i < 4; ++i) {
        if(cnt[i] && v[i][3]) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}