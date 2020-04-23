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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    int B = ceil(sqrt(n));
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    vector<int> dep(n);
    vector<int> v;
    dep[0] = 1;
    vector<vector<int>> cnt(B);
    cnt[1].emplace_back(0);
    auto dfs = [&](int x, int p, auto &&f) -> void{
        v.emplace_back(x);
        for (auto &&y : G[x]) {
            if(!dep[y]) {
                dep[y] = dep[x]+1;
                cnt[dep[y]%(B-1)].emplace_back(y);
                f(y, x, f);
            }
            else if(dep[x]-dep[y] + 1 >= B){
                puts("2");
                printf("%d\n", dep[x]-dep[y]+1);
                for (int i = dep[y]-1; i < dep[x]; ++i) {
                    if(i >= dep[y]) printf(" ");
                    printf("%d", v[i]+1);
                }
                puts("");
                exit(0);
            }
        }
        v.pop_back();
    };
    dfs(0, -1, dfs);
    puts("1");
    for (int i = 0; i < B; ++i) {
        if(cnt[i].size() >= B){
            for (int j = 0; j < B; ++j) {
                if(j) printf(" ");
                printf("%d", cnt[i][j]+1);
            }
            puts("");
            break;
        }
    }
    return 0;
}