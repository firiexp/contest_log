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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<vector<int>> G(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a-1].emplace_back(b-1);
        G[b-1].emplace_back(a-1);
    }
    deque<int> Q;
    vector<int> num(n);
    {
        stack<int> s;
        int cnt = 0;
        vector<int> visited(n, 0);
        s.emplace(0);
        while(!s.empty()){
            int a = s.top(); s.pop();
            visited[a]++;
            num[a] = cnt++;
            Q.emplace_front(a);
            for (auto &&i : G[a]) {
                if(!visited[i]) s.emplace(i);
            }
        }
    }
    auto dp = make_v(2, n, n, INF<ll>);
    vector<int> sz(n, 1);
    while(!Q.empty()){
        int x = Q.front(); Q.pop_front();
        dp[v[x] < 0][x][0] = v[x];
        for (auto &&i : G[x]) {
            if(num[i] < num[x]) continue;
            auto tmp = make_v(2, sz[i]+sz[x], INF<ll>);
            for (int j = 0; j < sz[x]; ++j) {
                for (int k = 0; k < sz[i]; ++k) {
                    for (int a = 0; a < 2; ++a) {
                        if(dp[a][x][j] == INF<ll>) continue;
                        if(dp[0][i][k] != INF<ll>) tmp[a][j+k] = min(tmp[a][j+k], dp[a][x][j]+dp[0][i][k]);
                        if(dp[1][i][k] != INF<ll>) tmp[1][j+k] = min(tmp[1][j+k], dp[a][x][j]+dp[1][i][k]);
                        if(dp[0][i][k] != INF<ll>) tmp[a][j+k+1] = min(tmp[a][j+k+1], dp[a][x][j]);
                        if(dp[1][i][k] < 0) tmp[a][j+k+1] = min(tmp[a][j+k+1], dp[a][x][j]);
                    }
                }
            }
            sz[x] += sz[i];
            for (int j = 0; j < sz[x]; ++j) {
                for (int a = 0; a < 2; ++a) {
                    dp[a][x][j] = tmp[a][j];
                }
            }
        }
    }
    int ans = INF<int>;
    for (int i = 0; i < n; ++i) {
        if(dp[0][0][i] != INF<ll>) ans = min(ans, i);
        if(dp[1][0][i] < 0) ans = min(ans, i);
    }
    cout << ans << "\n";
    return 0;
}
