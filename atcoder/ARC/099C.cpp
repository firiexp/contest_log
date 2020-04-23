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
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }
class UnionFind {
    vector<int> uni;
    int n;
public:
    explicit UnionFind(int n) : uni(static_cast<u32>(n), -1) , n(n){};

    int root(int a){
        if (uni[a] < 0) return a;
        else return (uni[a] = root(uni[a]));
    }

    bool unite(int a, int b) {
        a = root(a);
        b = root(b);
        if(a == b) return false;
        if(uni[a] > uni[b]) swap(a, b);
        uni[a] += uni[b];
        uni[b] = a;
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    auto v = make_v(n, n, 0);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        v[x-1][y-1] = v[y-1][x-1] = 1;
    }
    vector<vector<int>> G(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i != j && !v[i][j]) G[i].emplace_back(j);
        }
    }
    vector<int> used(n), color(n, -1);
    stack<int> s;
    for (int x = 0; x < n; ++x) {
        if(used[x]) continue;
        color[x] = 0;
        s.emplace(x);
        while(!s.empty()){
            int i = s.top(); s.pop();
            used[i] = 1;
            for (auto &&j : G[i]) {
                if(color[j] == color[i]){
                    puts("-1");
                    return 0;
                }
                color[j] = 1-color[i];
                if(!used[j]) s.emplace(j);
            }
        }
    }
    UnionFind uf(n);
    for (int i = 0; i < n; ++i) {
        for (auto &&j : G[i]) {
            uf.unite(i, j);
        }
    }
    vector<pair<int, int>> colors(n, {0, 0});
    for (int i = 0; i < n; ++i) {
        if(color[i] == 0) colors[uf.root(i)].first++;
        else colors[uf.root(i)].second++;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if(colors[i] != make_pair(0, 0)) cnt++;
    }
    vector<bitset<1000>> dp(cnt+1);
    dp[0].set(0);
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if(colors[i] != make_pair(0, 0)){
            dp[cur+1] |= dp[cur] << colors[i].first;
            dp[cur+1] |= dp[cur] << colors[i].second;
            cur++;
        }
    }
    ll ans = INF<ll>;
    for (ll i = 0; i <= n; ++i) {
        if(dp[cur][i]){
            chmin(ans, i*(i-1)/2+(n-i)*(n-i-1)/2);
        }
    }
    cout << ans << "\n";
    return 0;
}
