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
    set<int> s;
    for (int i = 0; i < n; ++i) {
        s.insert(i);
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    for (int i = 0; i < n; ++i) {
        sort(G[i].begin(),G[i].end());
    }
    int ans = 0;
    auto dfs = [&](int v, auto &&f) -> void {
        s.erase(v);
        while(true){
            int to = -1;
            for(auto it = s.begin(); it != s.end(); ++it) {
                auto x = lower_bound(G[v].begin(),G[v].end(), *it);
                if(G[v].empty() || x == G[v].end() ||(*x != *it)){
                    to = *it;
                    break;
                }
            }
            if(to == -1) break;
            f(to, f);
        }
    };
    for (int i = 0; i < n; ++i) {
        if(s.count(i)){
            ans++;
            dfs(i, dfs);
        }
    }
    printf("%d\n", ans-1);
    return 0;
}