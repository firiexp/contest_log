#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ",";
        os << v[i];
    }
    return os << "]";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.first << "," << p.second << ")";
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n), visited(n), tmp(n);
    vector<vector<int>> cycles;
    for (int i = 0; i < n; ++i) {
        cin >> tmp[i];
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v[tmp[i]-1] = x-1;
    }
    for (int i = 0; i < n; ++i) {
        if(visited[i]) continue;
        vector<int> x;
        int w = i;
        while (!visited[w]){
            x.emplace_back(w+1);
            visited[w] = 1;
            w = v[w];
        }
        x.emplace_back(w+1);
        cycles.emplace_back(x);
    }
    vector<int> ans{0};
    for (auto &&cycle : cycles) {
        int m = static_cast<int>(cycle.size())-1;
        vector<int> partial_ans(m+1, -INF<int>);
        for (int c = 0; c < 2; ++c) {
            auto dp = make_v(2, m+2, 2, -INF<int>);
            dp[0][1][c] = cycle[c];
            for (int i = 1; i < m; ++i) {
                int nxt = i%2, now = nxt^1;
                for (int j = 0; j <= m; ++j) {
                    if(dp[now][j][0] >= 0){
                        dp[nxt][j+1][0] = max(dp[nxt][j+1][0], dp[now][j][0] + cycle[i]);
                        dp[nxt][j+1][1] = max(dp[nxt][j+1][1], dp[now][j][0] + cycle[i+1]);
                    }
                    if(dp[now][j][1] >= 0){
                        dp[nxt][j][0] = max(dp[nxt][j][0], dp[now][j][1] + cycle[i]);
                        dp[nxt][j+1][1] = max(dp[nxt][j+1][1], dp[now][j][1] + cycle[i+1]);
                    }
                    dp[now][j][0] = dp[now][j][1] = -INF<int>;
                }
            }
            for (int i = 0; i <= m; ++i) {
                for (int j = 0; j < 2; ++j) {
                    partial_ans[i] = max(partial_ans[i], dp[(m+1)%2][i][j]);
                }
            }

        }

        int p = ans.size(), q = partial_ans.size();
        vector<int> ans2(p+q-1, 0);
        for (int i = 0; i < p; ++i) {
            for (int j = 0; j < q; ++j) {
                ans2[i+j] = max(ans2[i+j], ans[i] + partial_ans[j]);
            }
        }
        swap(ans, ans2);
    }
    int ret = 0;
    for (int i = k; i <= n; ++i) {
        ret = max(ret, ans[i]);
    }
    cout << ret << "\n";
    return 0;
}
