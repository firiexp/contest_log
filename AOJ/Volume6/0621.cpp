#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <numeric>

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
    int h, w;
    cin >> h >> w;
    auto v = make_v(3, h+1, 0);
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            if(s[j] == 'W') v[0][i+1]++;
            if(s[j] == 'B') v[1][i+1]++;
            if(s[j] == 'R') v[2][i+1]++;
        }
    }
    for (int k = 0; k < 3; ++k) {
        partial_sum(v[k].begin(), v[k].end(), v[k].begin());
    }
    int ans = INF<int>;
    for (int i = 1; i <= h-2; ++i) {
        for (int j = i+1; j <= h-1; ++j) {
            ans = min(ans,
                      (v[0][h]-v[0][i])+v[1][i]+v[1][h]-v[1][j]+v[2][j]
                    );
        }
    }
    cout << ans << "\n";
    return 0;
}
