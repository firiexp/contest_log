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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }


template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ", ";
        os << v[i];
    }
    return os << "}";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "{" << p.first << ", " << p.second << "}";
}


int main() {
    int h, w;
    cin >> h >> w;
    auto v = make_v(h+2, w+2, 0);
    auto dp = make_v(h+2, w+2, -1);
    vector<pair<int, int>> u(h*w);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            scanf("%d", &v[i+1][j+1]);
            u[i*w+j] = {i+1, j+1};
        }
    }
    using P = pair<int, int>;
    sort(u.begin(),u.end(), [&v](P a, P b){
        return v[a.first][a.second] < v[b.first][b.second];
    });
    array<int, 4> dy{-1, 1, 0, 0}, dx{0, 0, 1, -1};
    int ans = 0;
    for (int i = 0; i < h*w; ++i) {
        int y, x; tie(y, x) = u[i];
        for (int k = 0; k < 4; ++k) {
            if(dp[y+dy[k]][x+dx[k]] == -1) continue;
            else if(dp[y+dy[k]][x+dx[k]] == -2) dp[y][x] = -2;
            else if(dp[y][x] >= 0 && dp[y+dy[k]][x+dx[k]] != dp[y][x]){
                dp[y][x] = -2;
            } else dp[y][x] = dp[y+dy[k]][x+dx[k]];
            if(dp[y][x] == -2) break;
        }
        if(dp[y][x] == -1) dp[y][x] = v[y][x];
        if(dp[y][x] == -2) ans++;
    }
    cout << ans << "\n";
    return 0;
}