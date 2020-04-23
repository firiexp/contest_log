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
    int n; ll d;
    cin >> n >> d;
    vector<int> v(3), u{2, 3, 5};
    for (int i = 0; i < 3; ++i) {
        while(d % u[i] == 0) d /= u[i], v[i]++;
    }
    if(d != 1){
        puts("0");
        return 0;
    }

    auto dp = make_v(n+1, v[0]+1, v[1]+1, v[2]+1, 0.0);
    dp[0][0][0][0] = 1.0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= v[0]; ++j) {
            for (int k = 0; k <= v[1]; ++k) {
                for (int l = 0; l <= v[2]; ++l) {
                    double x = dp[i][j][k][l]/6;
                    dp[i+1][j][k][l] += x;
                    dp[i+1][min(v[0], j+1)][k][l] += x;
                    dp[i+1][j][min(v[1], k+1)][l] += x;
                    dp[i+1][min(v[0], j+2)][k][l] += x;
                    dp[i+1][j][k][min(v[2], l+1)] += x;
                    dp[i+1][min(v[0], j+1)][min(v[1], k+1)][l] += x;
                }
            }
        }
    }
    printf("%.10f\n", dp[n][v[0]][v[1]][v[2]]);
    return 0;
}
