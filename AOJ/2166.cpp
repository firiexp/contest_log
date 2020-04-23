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
    while(cin >> t, t){
        vector<int> v(t);
        for (auto &&i : v) scanf("%d", &i);
        int n;
        cin >> n;
        int M = 101;
        vector<int> u(M, 24);
        for (int i = 0; i < n; ++i) {
            int d, m;
            cin >> d >> m;
            u[d-1] = min(u[d-1], m);
        }
        auto dp = make_v(M, t, INF<int>);
        dp[0][0] = 0;
        for (int i = 1; i < M; ++i) {
            for (int j = 0; j < t; ++j) {
                if(v[(j+1)%t] <= u[i]) chmin(dp[i][(j+1)%t], dp[i-1][j]);
                chmin(dp[i][0], dp[i-1][j]+1);
            }
        }
        cout << *min_element(dp.back().begin(),dp.back().end()) << "\n";
    }
    return 0;
}