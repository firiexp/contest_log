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
    auto v2 = v;
    for (int i = 1; i < h-1; ++i) {
        if(i&1){
            for (int j = 1; j < w-1; ++j) {
                v[i][j] = 1;
            }
        }else {
            if(i&2){
                v[i][1] = 1;
            }else {
                v[i][w-2] = 1;
            }
        }
    }
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            v2[i][j] = 1-v[i][j];
            if(s[j] == '#'){
                v2[i][j] = v[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << (v[i][j] ? '#' : '.');
        }
        cout << "\n";
    }
    cout << "\n";
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << (v2[i][j] ? '#' : '.');
        }
        cout << "\n";
    }
    return 0;
}
