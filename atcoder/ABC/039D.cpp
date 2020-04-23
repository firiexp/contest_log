#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }


int main() {
    int h, w;
    cin >> h >> w;
    auto v = make_v(h+2, w+2, 0);
    auto v2 = v;
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            v[i+1][j+1] = (s[j] == '.');
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            for (int k = -1; k < 2; ++k) {
                for (int l = -1; l < 2; ++l) {
                    v2[i+1][j+1] |= v[i+1+k][j+1+l];
                }
            }
            v2[i+1][j+1]^=1;
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int x = 0;
            for (int k = -1; k < 2; ++k) {
                for (int l = -1; l < 2; ++l) {
                    x |= v2[i+1+k][j+1+l];
                }
            }
            if(v[i+1][j+1] == x){
                puts("impossible");
                return 0;
            }
        }
    }
    puts("possible");
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            printf("%c", (v2[i+1][j+1] ? '#' : '.'));
        }
        puts("");
    }
    return 0;
}
