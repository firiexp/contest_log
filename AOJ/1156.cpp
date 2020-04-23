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

struct edge {
    int to, cost;
    edge(int to, int cost) : to(to), cost(cost){};
};

int main() {

    int w, h;
    while(cin >> w >> h, w){
        vector<vector<edge>> G(h*w*4);
        array<int, 4> di{0, 1, 0, -1}, dj{1, 0, -1, 0};
        vector<vector<int>> v(h+2, vector<int>(w+2, -1));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> v[i+1][j+1];
            }
        }
        array<int, 4> costs{};
        for (auto &&k : costs) cin >> k;
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                for (int k = 0; k < 4; ++k) {
                    for (int un = 0; un < 4; ++un) {
                        int l = (k+un)%4;
                        if(!(~v[i+di[l]][j+dj[l]])) continue;
                        int c = (v[i][j] == un ? 0 : costs[un]);
                        i--; j--;
                        G[(i*w+j)*4+k].emplace_back(((i+di[l])*w+j+dj[l])*4+l, c);
                        i++; j++;
                    }
                }
            }
        }
        using P = pair<int, int>;
        vector<int> dist(G.size(), INF<int>);
        priority_queue<P, vector<P>, greater<>> Q;
        dist[0] = 0;
        Q.emplace(0, 0);
        while(!Q.empty()){
            int cost, i; tie(cost, i) = Q.top(); Q.pop();
            if(dist[i] < cost) continue;
            for (auto &&e : G[i]) {
                if(dist[e.to] <= cost + e.cost) continue;
                dist[e.to] = cost + e.cost;
                Q.emplace(dist[e.to], e.to);
            }
        }
        int ans = INF<int>;
        for (int i = 0; i < 4; ++i) {
            ans = min(ans, dist[(h*w-1)*4+i]);
        }
        cout << ans << "\n";
    }
    return 0;
}