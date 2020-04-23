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
    int n, m, d;
    cin >> n >> m >> d;
    auto v = make_v(n, m, 0);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            v[i][j] = (s[j] == '.');
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int k = 0;
        for (int j = 0; j < m; ++j) {
            if(v[i][j]) k++;
            else k = 0;
            if(k >= d) ans++;
        }
    }
    for (int i = 0; i < m; ++i) {
        int k = 0;
        for (int j = 0; j < n; ++j) {
            if(v[j][i]) k++;
            else k = 0;
            if(k >= d) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
