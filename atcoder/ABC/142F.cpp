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



int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a-1].emplace_back(b-1);
    }

    int ans = INF<int>;
    for (int i = 0; i < n; ++i) {
        vector<int> d(n, INF<int>), visited(n, 0);
        queue<int> Q;
        for (auto &&l : G[i]) {
            d[l] = 1;
            Q.emplace(l);
            visited[l] = 1;
        }
        while(!Q.empty()){
            int j = Q.front(); Q.pop();
            for (auto &&k : G[j]) {
                if(!visited[k]){
                    visited[k] = 1;
                    d[k] = d[j]+1;
                    Q.emplace(k);
                }
            }
        }
        ans = min(ans, d[i]);
    }
    if(ans == INF<int>) {
        puts("-1");
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        vector<int> d(n, INF<int>), visited(n, 0), par(n, 0);
        queue<int> Q;
        for (auto &&l : G[i]) {
            d[l] = 1;
            Q.emplace(l);
            visited[l] = 1;
        }
        while(!Q.empty()){
            int j = Q.front(); Q.pop();
            for (auto &&k : G[j]) {
                if(!visited[k]){
                    visited[k] = 1;
                    d[k] = d[j]+1;
                    Q.emplace(k);
                    par[k] = j;
                }
            }
        }
        if(ans == d[i]){
            vector<int> ret{i};
            int cur = i;
            while(par[cur] != 0){
                ret.emplace_back(par[cur]);
                cur = par[cur];
            }
            cout << ret.size() << "\n";
            for (auto &&j : ret) cout << j+1 << "\n";
            return 0;
        }
    }
    puts("-1");
    return 0;
}