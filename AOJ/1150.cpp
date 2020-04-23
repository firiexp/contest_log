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

struct edge{
    int cost, to;
    edge(int cost, int to) : cost(cost), to(to) {};
};

int main() {
    int w, h;
    while(cin >> w >> h, w){
        vector<vector<edge>> G(h*w*2);
        vector<vector<int>> v(h, vector<int> (w, MOD));
        vector<int> dist(h*w*2, MOD);
        vector<int> goal;
        auto f = [&w](int i, int j, int k){ return (i*w+j)*2+k;};
        using P = pair<int, int>;
        priority_queue<P, vector<P>, greater<>> Q;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                char c;
                cin >> c;
                if(isdigit(c)) v[i][j] = c-'0';
                else if(c == 'S') {
                    v[i][j] = 0, dist[f(i, j, 0)] = dist[f(i, j, 1)] = 0;
                    Q.emplace(0, f(i, j, 0)); Q.emplace(0, f(i, j, 1));
                }
                else if(c == 'T') {
                    v[i][j] = 0;
                    goal.emplace_back(f(i, j, 0)), goal.emplace_back(f(i, j, 1));
                }
            }
        }

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                for (int k = 0; k < h; ++k) {
                    for (int l = 0; l < j; ++l) {
                        if(abs(k-i)+abs(j-l) <= 3){
                            if(v[k][l] != MOD) G[f(i, j, 0)].emplace_back(v[k][l] , f(k, l, 1));
                        }
                    }
                }
            }
        }
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                for (int k = 0; k < h; ++k) {
                    for (int l = j+1; l < w; ++l) {
                        if(abs(k-i)+abs(j-l) <= 3){
                            if(v[k][l] != MOD) G[f(i, j, 1)].emplace_back(v[k][l], f(k, l, 0));
                        }
                    }
                }
            }
        }

        while(!Q.empty()){
            int cost, i; tie(cost, i) = Q.top(); Q.pop();
            if(dist[i] < cost) continue;
            for (auto &&e : G[i]) {
                if(dist[e.to] <= cost + e.cost) continue;
                dist[e.to] = cost + e.cost;
                Q.emplace(dist[e.to], e.to);
            }
        }
        int ans = MOD;
        for (auto &&i : goal) {
            ans = min(ans, dist[i]);
        }
        cout << (ans == MOD ? -1 : ans) << "\n";
    }
    return 0;
}