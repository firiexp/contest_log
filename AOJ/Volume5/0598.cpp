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
    int h, w;
    cin >> h >> w;
    auto v = make_v(h+2, w+2, 'X');
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            v[i+1][j+1] = s[j];
        }
    }
    string s[2];
    cin >> s[0] >> s[1];
    int ans = 0;
    for (int i = 1; i < h; ++i) {
        for (int j = 1; j < w; ++j) {
            int x = 0;
            if(v[i][j] == s[0][0] && v[i][j+1] == s[0][1] && v[i+1][j] == s[1][0] && v[i+1][j+1] == s[1][1]) ans++;
        }
    }
    int ans2 = 0;
    string t = "JOI";
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            char tmp = v[i+1][j+1];
            int p = 0;
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < 2; ++l) {
                    if(v[i+k][j+l] == s[0][0] && v[i+k][j+1+l] == s[0][1] &&
                    v[i+1+k][j+l] == s[1][0] && v[i+1+k][j+1+l] == s[1][1]) p--;
                }
            }
            for (auto &&q : t) {
                v[i+1][j+1] = q;
                int pp = p;
                for (int k = 0; k < 2; ++k) {
                    for (int l = 0; l < 2; ++l) {
                        if(v[i+k][j+l] == s[0][0] && v[i+k][j+1+l] == s[0][1] &&
                           v[i+1+k][j+l] == s[1][0] && v[i+1+k][j+1+l] == s[1][1]) pp++;
                    }
                }
                ans2 = max(ans2, pp);
            }
            v[i+1][j+1] = tmp;
        }
    }
    cout << ans + ans2 << "\n";
    return 0;
}
