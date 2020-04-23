#include <iostream>
#include <algorithm>
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
    int n;
    while(cin >> n, n){
        array<int, 11> cnt{};
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            cnt[x]++;
        }
        int ans = 0;
        while(cnt[1] && cnt[9]) cnt[1]--, cnt[9]--, ans++;
        while(cnt[2] && cnt[8]) cnt[2]--, cnt[8]--, ans++;
        while(cnt[3] && cnt[7]) cnt[3]--, cnt[7]--, ans++;
        while(cnt[4] && cnt[6]) cnt[4]--, cnt[6]--, ans++;
        while(cnt[5] >= 2) cnt[5] -= 2, ans++;
        vector<pair<int, int>> v;
        for (int i = 1; i < 9; ++i) if(cnt[i]) v.emplace_back(cnt[i], i);
        while(v.size() < 5) v.emplace_back(0, 0);
        using A = array<char, 5>;
        A x;
        for (int i = 0; i < v.size(); ++i) x[i] = v[i].first;
        vector<A> ok;
        for (char i = 0; i <= v[0].first; ++i) {
            for (char j = 0; j <= v[1].first; ++j) {
                for (char k = 0; k <= v[2].first; ++k) {
                    for (char l = 0; l <= v[3].first; ++l) {
                        for (char m = 0; m <= v[4].first; ++m) {
                            if(i*v[0].second+j*v[1].second+k*v[2].second+l*v[3].second+m*v[4].second == 10) ok.emplace_back(A{i, j, k, l, m});
                        }
                    }
                }
            }
        }
        map<A, int> dp;
        auto dfs = [&](A x, int dep, auto &&f) -> int {
            if(dp.count(x)) return dp[x];
            int ret = dep;
            for (int i = 0; i < ok.size(); ++i) {
                A y;
                for (int j = 0; j < 5; ++j) y[j] = x[j]-ok[i][j];
                if(*min_element(y.begin(),y.end()) >= 0) ret = max(ret, f(y, dep+1, f));
            }
            return dp[x] = ret;
        };
        cout << dfs(x, ans, dfs) << "\n";
    }
    return 0;
}