#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <typename T>
struct edge {
    int from, to;
    T cost;

    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}

    explicit operator int() const {return to;}
};

template <typename T>
vector<T> dijkstra(int s, vector<vector<edge<T>>> &G){
    uint64_t n=G.size();
    const T INF = numeric_limits<T>::max();
    using P = pair<T, int>;
    vector<T> d(n, INF);
    vector<int> b(n,-1);
    priority_queue<P,vector<P>,greater<> > Q;
    d[s]=0;
    Q.emplace(d[s],s);
    while(!Q.empty()){
        T cost;
        int i;
        tie(cost, i) = Q.top(); Q.pop();
        if(d[i] < cost) continue;
        for (auto &&e : G[i]) {
            auto cost2 = cost + e.cost;
            if(d[e.to] <= cost2) continue;
            d[e.to] = cost2;
            Q.emplace(d[e.to], e.to);
        }
    }
    return d;
}


int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};



int main() {
    int h, w, t, sy, sx, gy, gx;
    cin >> h >> w >> t;
    vector<vector<int>> grid(h, vector<int>(w, 0));
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            if(s[j] == 'S')sy = i, sx = j;
            if(s[j] == 'G')gy = i, gx = j;
            if(s[j] == '#') grid[i][j] = 1;
            else grid[i][j] = 0;
        }
    }
    ll l = 1, r = t+1;
    while((r > l ? r-l: l-r) > 1){
        ll mid = (r+l)/2;
        vector<vector<edge<ll>>> G(w*h);
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                for (int k = 0; k < 4; ++k) {
                    int p = i+dy[k], q = j + dx[k];
                    if(0 <= p && p < h && 0 <= q && q < w){
                        if(grid[i][j] == 1) G[w*p+q].push_back(edge<ll>(w*i+j, mid));
                        else G[w*p+q].push_back(edge<ll>(w*i+j, 1));
                    }
                }
            }
        }
        auto v = dijkstra(w*sy+sx, G);
        if(v[w*gy+gx] <= t){
            l = mid;
        }else r = mid;
    }
    cout << l << "\n";
    return 0;
}
