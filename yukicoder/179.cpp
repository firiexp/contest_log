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
    auto v = make_v(h, w, 0);
    int cnt = 0;
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            v[i][j] = s[j] == '#';
            cnt += v[i][j];
        }
    }
    if(!cnt){
        puts("NO");
        return 0;
    }
    for (int di = 0; di < h; ++di) {
        for (int dj = -w+1; dj < w; ++dj) {
            if(di == 0 && dj <= 0) continue;
            auto vv = v;
            int valid = true;
            for (int i = 0; i < h; ++i) {
                for (int j = 0; j < w; ++j) {
                    if(vv[i][j]){
                        if(i+di < 0 || j+dj < 0 || i+di >= h || j+dj >= w){
                            valid = false;
                            break;
                        }
                        if(vv[i+di][j+dj]){
                            vv[i][j] = vv[i+di][j+dj] = 0;
                        }else {
                            valid = false;
                            break;
                        }
                    }
                }
            }
            if(valid){
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}
