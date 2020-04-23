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
#include <cassert>

static const int MOD = 1000000007;
using ll = long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int t;
    cin >> t;
    if(t == 1){
        int n, k;
        cin >> n >> k;
        auto dp = make_v(1<<n, (1<<n)+1, make_tuple(-1, -1, -1, -1, -1));
        vector<int> cnt(1 << n);
        for (int i = 0; i < (1 << n); ++i) {
            for (int j = 0; j < n; ++j) {
                if(i & (1 << j)) {
                    cnt[i] = cnt[i^(1 << j)] + 1;
                    break;
                }
            }
        }
        tuple<int, int, int, int, int> NG = make_tuple(-1, -1, -1, -1, -1);
        for (int mask = 0; mask < (1<<n); ++mask) {
            if(cnt[mask] == 1){
                dp[mask][1] = make_tuple(0, 0, 0, 0, 0);
            }
            for (int j = (mask-1)&mask; j > 0; j = (j-1)&mask) {
                int i = mask^j;
                for (int x = 0; x < (1 << cnt[i]); ++x) {
                    int xx = (1 << cnt[i])-x;
                    if(dp[i][x] == NG) continue;
                    for (int y = 0; y < (1 << cnt[j]); ++y) {
                        if(dp[j][y] == NG) continue;
                        int yy = (1 << cnt[j])-y;
                        dp[mask][x*y] = make_tuple(i, j, x, y, 0); // AND
                        dp[mask][(xx+x)*(yy+y)-xx*yy] = make_tuple(i, j, x, y, 1);
                        dp[mask][x*yy+y*xx] = make_tuple(i, j, x, y, 2);
                    }
                }
            }
        }
        int val = n;
        cout << n-1 << "\n";
        auto dfs = [&](int p, int q, auto &&f) -> int {
            if(cnt[p] == 1){
                return __builtin_ctz(p);
            }
            int i, j, xxx, yyy, e; tie(i, j, xxx, yyy, e) = dp[p][q];
            string zzz;
            if(e == 0) zzz = "AND";
            else if(e == 1) zzz = "OR";
            else zzz = "XOR";
            int a = f(i, xxx, f);
            int b = f(j, yyy, f);
            cout << zzz << " " << a+1 << " " << b+1 << "\n";
            return val++;
        };
        dfs((1 << n)-1, k, dfs);
    }else {
        assert(0);
    }
    return 0;
}