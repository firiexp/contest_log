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
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n-1; ++i) {
        string x = s.substr(0, i+1), y = s.substr(i+1, n);
        auto dp = make_v(x.size()+1, y.size()+1, 0);
        for (int j = 0; j < x.size(); ++j) {
            for (int k = 0; k < y.size(); ++k) {
                if(x[j] == y[k]) chmax(dp[j+1][k+1], dp[j][k]+1);
                chmax(dp[j+1][k+1], max(dp[j+1][k], dp[j][k+1]));
            }
        }
        ans = max(ans, dp[x.size()][y.size()]*2);

    }
    cout << n-ans << "\n";
    return 0;
}
