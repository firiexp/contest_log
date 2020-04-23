#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
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
    vector<vector<int>> v(h+2, vector<int>(w+2, INF<int>));
    auto dist = v;
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            v[i+1][j+1] = s[j] == '.';
        }
    }
    dist[1][1] = 1-v[1][1];
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if(i != 1) chmin(dist[i][j], dist[i-1][j]+(v[i][j] != v[i-1][j]));
            if(j != 1) chmin(dist[i][j], dist[i][j-1]+(v[i][j] != v[i][j-1]));
        }
    }
    cout << (dist[h][w]+1)/2 << "\n";
    return 0;
}