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
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> v(h);
    for (auto &&i : v) cin >> i;
    int ans = INF<int>;
    auto dp = make_v(h, w, 0);
    vector<int> cnt(h);
    for (int a = 0; a < (1 << (h-1)); ++a) {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                dp[i][j] = 0;
            }
            cnt[i] = 0;
        }
        int cur = 0;
        int ok = 1;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                dp[cur][j] += v[i][j] - '0';
            }
            if(a & (1 << i)) cur++;
        }
        int val = cur++;
        for (int j = 0; j < w; ++j) {
            int good = 1;
            for (int i = 0; i < cur; ++i) {
                cnt[i] += dp[i][j];
                if(cnt[i] > k){
                    good = 0;
                }
            }
            if(!good){
                val++;
                for (int i = 0; i < cur; ++i) {
                    cnt[i] = dp[i][j];
                    if(dp[i][j] > k) ok = 0;
                }
                if(!ok) break;
            }
        }
        if(ok){
            ans = min(ans, val);
        }
    }
    cout << ans << "\n";
    return 0;
}