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



template <class K, class V>
class RadixHeap {
    static constexpr int bit_length = sizeof(K)*8;
    K last;
    size_t sz, cnt;
    array<vector<pair<K, V>>, bit_length> v;
    static inline int bsr(int x){
        return x ? bit_length-__builtin_clz(x) : 0;
    }
    static inline int bsr(ll x){
        return x ? bit_length-__builtin_clzll(x) : 0;
    }

    void pull() {
        if(cnt < v[0].size()) return;;
        int i = 1;
        while(v[i].empty()) i++;
        last = min_element(v[i].begin(),v[i].end())->first;
        for (auto &&x : v[i]) v[bsr(x.first ^ last)].push_back(x);
        v[i].clear();
    }
public:
    RadixHeap() : last(0), sz(0), cnt(0) {}
    void emplace(K x, V val){
        sz++;
        v[bsr(x^last)].emplace_back(x, val);
    }

    pair<K, V> top() {
        pull();
        return v[0][cnt];
    }

    void pop() {
        pull();
        sz--;
        cnt++;
    }

    size_t size() const { return sz; }
    bool empty() const { return !sz; }
};

template <typename T>
struct edge {
    int from, to; T cost;
    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};

int main() {
    int n, v, sx, sy, gx, gy;
    cin >> n >> v >> sx >> sy >> gx >> gy;
    sx--; sy--; gx--; gy--;
    int m = min(v-1, n*18);
    auto dp = make_v(n*n, m+1, INF<int>); // dp[i][j] : point:i , hp:j
    auto grid = make_v(n+2, n+2, INF<int>);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &grid[i+1][j+1]);
        }
    }
    auto f = [&](int i, int j){ return i*n+j; };
    RadixHeap<int, pair<int, int>> Q;
    dp[f(sy, sx)][0] = 0;
    Q.emplace(0, {f(sy, sx), 0});
    array<int, 4> dy{-1, 1, 0, 0}, dx{0, 0, -1, 1};
    while(!Q.empty()){
        int cost; pair<int, int> i;
        tie(cost, i) = Q.top(); Q.pop();
        if(dp[i.first][i.second] < cost) continue;
        if(i.first == f(gy, gx)){
            cout << cost << "\n";
            return 0;
        }
        int x = i.first/n, y = i.first % n;
        for (int k = 0; k < 4; ++k) {
            auto to = i.second + grid[x+dx[k]+1][y+dy[k]+1];
            if(to > m || dp[f(x+dx[k], y+dy[k])][to] <= cost+1) continue;
            dp[f(x+dx[k], y+dy[k])][to] = cost + 1;
            Q.emplace(cost+1, {f(x+dx[k], y+dy[k]), to});
        }
    }
    puts("-1");
    return 0;
}