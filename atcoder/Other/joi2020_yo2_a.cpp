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
    auto s = make_v(n, n, char());
    auto t = s;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> s[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> t[i][j];
        }
    }
    array<int, 4> ans{0, 1, 1, 2};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(s[i][j] != t[i][j]) ans[0]++;
            if(s[i][j] != t[j][n-i-1]) ans[1]++;
            if(s[i][j] != t[n-j-1][i]) ans[2]++;
            if(s[i][j] != t[n-i-1][n-j-1]) ans[3]++;
        }
    }
    cout << *min_element(ans.begin(),ans.end()) << "\n";
    return 0;
}