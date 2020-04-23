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

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> G(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        G[a].emplace_back(b, i);
        G[b].emplace_back(a, i);
    }
    vector<int> dist(n, INF<int>);
    dist[0] = 0;
    {
        queue<int> Q;
        Q.emplace(0);
        while(!Q.empty()){
            int i = Q.front(); Q.pop();
            for (auto &&j : G[i]) {
                if(dist[j.first] > dist[i]+1){
                    dist[j.first] = dist[i]+1;
                    Q.emplace(j.first);
                }
            }
        }
    }
    vector<int> v(m);

    vector<vector<pair<int, int>>> G2(n);
    ll val = 1;
    for (int i = 0; i < n; ++i) {
        for (auto &&j : G[i]) {
            if(dist[j.first]+1 <= dist[i]) G2[i].emplace_back(j);
        }
        if(i) val = min<ll>(k, val*G2[i].size());
    }
    cout << val << "\n";
    vector<int> ans(m);
    for (int i = 0; i < val; ++i) {
        ll cur = i;
        fill(ans.begin(),ans.end(), 0);
        for (int j = 0; j < n; ++j) {
            if(!G2[j].empty()){
                ans[G2[j][cur%G2[j].size()].second] = 1;
                cur /= G2[j].size();
            }
        }
        for (int j = 0; j < m; ++j) printf("%d", ans[j]);
        puts("");
    }
    return 0;
}