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

#include <chrono>
class xor_shift {
    uint32_t x, y, z, w;
public:
    xor_shift() : x(static_cast<uint32_t>((chrono::system_clock::now().time_since_epoch().count())&((1LL << 32)-1))),
                  y(1068246329), z(321908594), w(1234567890) {};

    uint32_t urand(){
        uint32_t t;
        t = x ^ (x << 11);
        x = y; y = z; z = w;
        w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
        return w;
    };

    int rand(int n){
        if(n < 0) return -rand(-n);
        uint32_t t = numeric_limits<uint32_t>::max()/(n+1)*(n+1);
        uint32_t e = urand();
        while(e >= t) e = urand();
        return static_cast<int>(e%(n+1));
    }

    int rand(int a, int b){
        if(a > b) swap(a, b);
        return a+rand(b-a);
    }
};

template<typename F>
static inline constexpr decltype(auto) fix(F&& f) noexcept {
    return [f = std::forward<F>(f)](auto&&... args) {
        return f(f, std::forward<decltype(args)>(args)...);
    };
}


void solve(){
    int r, c;
    cin >> r >> c;
    vector<vector<int>> G(r*c);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            for (int k = 0; k < r; ++k) {
                if(i == k) continue;
                for (int l = 0; l < c; ++l) {
                    if(j == l) continue;
                    if(i-j == k-l) continue;
                    if(i+j == k+l) continue;
                }
            }
        }
    }
    xor_shift rd;
    vector<int> visited(r*c);
    int res = fix([&](auto dfs,int x, int dep) -> int {
        if(dep == r*c) return 1;
        int xx = G[x].size();
        for (int i = 0; i < xx; ++i) {
            int y = rd.rand(xx-i-2);
            swap(G[y], G[xx-i-2]);
        }
        for (auto &&y : G[x]) {
            if(!visited[y]){
                visited[y] = 1;
                int e = dfs(dfs, y, dep+1);
            }
        }
        return 0;
    })(0, 0);

}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
