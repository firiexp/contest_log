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

template <typename T>
struct edge {
    int to; T cost;
    edge(int to, T cost) : to(to), cost(cost) {}
};


template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

int main() {
    int n;
    while(cin >> n, n){
        vector<int> id(n), xs(n), ys(n);
        map<int, int> A, Ainv;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d %d", &id[i], &xs[i], &ys[i]);
            A[i] = id[i];
            Ainv[id[i]] = i;
        }
        vector<vector<edge<double>>> G(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if((xs[i]-xs[j])*(xs[i]-xs[j])+(ys[i]-ys[j])*(ys[i]-ys[j]) <= 2500){
                    G[i].emplace_back(j, hypot(xs[i]-xs[j], ys[i]-ys[j]));
                    G[j].emplace_back(i, hypot(xs[i]-xs[j], ys[i]-ys[j]));
                }
            }
        }
        int m;
        cin >> m;
        while(m--){
            int s, g;
            cin >> s >> g;
            vector<double> dist(n, 1e18);
            vector<int> prev(n);
            GPQ<pair<double, int>> Q;
            s = Ainv[s]; g = Ainv[g];
            Q.emplace(0, s);
            while(!Q.empty()){
                double cost; int i;
                tie(cost, i) = Q.top(); Q.pop();
                if(dist[i] < cost) continue;
                for (auto &&e : G[i]) {
                    auto cost2 = cost + e.cost;
                    if(dist[e.to] <= cost2) continue;
                    dist[e.to] = cost2;
                    Q.emplace(dist[e.to], e.to);
                    prev[e.to] = i;
                }
            }
            if(dist[g] > 1e16) {
                puts("NA");
                continue;
            }
            vector<int> ans;
            while(g != s){
                ans.emplace_back(g);
                g = prev[g];
            }
            ans.emplace_back(s);
            reverse(ans.begin(),ans.end());
            for (int i = 0; i < ans.size(); ++i) {
                printf(i ? " %d" : "%d", A[ans[i]]);
            }
            puts("");
        }
    }
    return 0;
}