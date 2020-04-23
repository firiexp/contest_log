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
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> G(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        G[a].emplace_back(b, i); G[b].emplace_back(a, i);
    }
    vector<int> v;
    auto dfs = [&](int x, int par, int dest, auto &&f) -> int {
        if(x == dest) return 1;
        for (auto &&i : G[x]) {
            if(i.first != par){
                v.emplace_back(i.second);
                if(f(i.first, x, dest, f)) return 1;
                v.pop_back();
            }
        }
        return 0;
    };
    int m;
    cin >> m;
    vector<array<int, 3>> query(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &query[i][1], &query[i][2], &query[i][0]);
        query[i][1]--; query[i][2]--;
    }
    sort(query.begin(),query.end(), greater<>());
    vector<int> ans(n-1, INF<int>);
    for (int i = 0; i < m; ++i) {
        v.clear();
        dfs(query[i][1], -1, query[i][2], dfs);
        int ok = 0;
        for (auto &&j : v) {
            if(query[i][0] > ans[j]){
                puts("-1");
                return 0;
            }else if(ans[j] == INF<int>){
                ans[j] = query[i][0];
                ok = 1;
            }else if(ans[j] == query[i][0]) {
                ok = 1;
            }
        }
        if(!ok){
            puts("-1");
            return 0;
        }
    }
    for (int i = 0; i < n-1; ++i) {
        if(i) printf(" ");
        printf("%d", (ans[i] == INF<int> ? 1000000 : ans[i]));
    }
    puts("");
    return 0;
}