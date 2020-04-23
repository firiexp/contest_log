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
    int h, w;
    cin >> h >> w;
    vector<string> v(h);
    int valid = 0;
    string t(w, '.');
    for (int i = 0; i < h; ++i) {
        cin >> v[i];
        if(v[i] == t) valid = 1;
    }
    auto dp = make_v(h+1, w+1, 0);
    dp[1][1] = 1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(i == 0 && j == 0) continue;
            dp[i+1][j+1] = (v[i][j] == '.') & (dp[i][j+1] | dp[i+1][j]);
        }
    }
    if(valid && dp[h][w]){
        puts("Yay!");
    }else {
        puts(":(");
    }
    return 0;
}
