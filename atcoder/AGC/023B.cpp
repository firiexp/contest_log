#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T>
vector<T> make_v(size_t size, const T& init){ return vector<T>(size, init); }

template<class... Ts>
auto make_v(size_t size, Ts... rest) { return vector<decltype(make_v(rest...))>(size, make_v(rest...)); }



int main() {
    int n;
    cin >> n;
    auto v = make_v(n, n, 0);
    auto dp = make_v(n, n, 0);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            v[i][j] = s[j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i == 0 || j == 0){
                int issym = 1;
                for (int k = 0; k < n; ++k) {
                    for (int l = k; l < n; ++l) {
                        if(v[(k+i)%n][(l+j)%n] != v[(l+i)%n][(k+j)%n]){
                            issym = 0;
                            k = l = n;
                        }
                    }
                }
                dp[i][j] = issym;
            }else {
                dp[i][j] = dp[i-1][j-1];
            }
            ans += dp[i][j];
        }
    }
    cout << ans << "\n";
    return 0;
}
