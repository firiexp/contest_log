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


int main() {
    int h, w;
    cin >> h >> w;
    int a, si, sj, b, gi, gj;
    cin >> a >> si >> sj >> b >> gi >> gj;
    auto v = make_v(h+2, w+2, 0);
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            v[i+1][j+1] = (s[j] == '*' ? 1 : -1);
        }
    }
    int m = h*w+1001;
    auto dp = make_v(h, w, m, 0);
    dp[si][sj][a] = 1;
    auto f = [&](int i, int j, int k){
        return i*w*m+j*m+k;
    };
    auto g = [&](int x) -> tuple<int, int, int> {
        return {x/w/m, x%(w*m)/m, x%m};
    };
    queue<int> Q;
    Q.emplace(f(si,  sj, a));
    array<int, 4> dy{1, -1, 0, 0}, dx{0, 0, -1, 1};
    while(!Q.empty()){
        int i, j, k;
        tie(i, j, k) = g(Q.front());
        if(i == gi && j == gj && k == b) {
            puts("Yes");
            return 0;
        }
        Q.pop();
        for (int l = 0; l < 4; ++l) {
            if(!v[i+dy[l]+1][j+dx[l]+1]) continue;
            int newk = k+v[i+dy[l]+1][j+dx[l]+1];
            if(newk <= 0 || newk >= m) continue;
            if(dp[i+dy[l]][j+dx[l]][newk]) continue;
            dp[i+dy[l]][j+dx[l]][newk] = 1;
            Q.emplace(f(i+dy[l], j+dx[l], newk));
        }
    }
    puts("No");
    return 0;
}