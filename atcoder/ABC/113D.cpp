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
    int h, w, k;
    cin >> h >> w >> k;
    auto dp = make_v(h+1, w, 0);
    dp[0][0] = 1;
    for (int i = 0; i < h; ++i) {
        for (int x = 0; x < (1 << (w-1)); ++x) {
            vector<int> v(w-1, 0);
            for (int j = 0; j < w-1; ++j) {
                if (x & (1<<j)) {
                    v[j] = 1;
                }
            }
            int z = 1;
            for (int j = 1; j < w-1; ++j) {
                if(v[j-1] && v[j]) z = 0;
            }
            vector<int> vv(w, 0);
            for (int l = 0; l < w; ++l) {
                vv[l] = l;
            }
            for (int j = 0; j < v.size(); ++j) {
                if(v[j]){
                    swap(vv[j], vv[j+1]);
                }
            }
            if(z){
                for (int j = 0; j < w; ++j) {
                    (dp[i+1][j] += dp[i][vv[j]]) %= MOD;
                }
            }
        }
    }
    cout << dp[h][k-1] << "\n";
    return 0;
}
