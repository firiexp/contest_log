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
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    vector<int> c(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    int x = -1, y = -1;
    for (auto &&j : c) scanf("%d", &j);
    for (int i = 0; i < n; ++i) {
        for (auto &&j : G[i]) {
            if(c[i] != c[j]) x = i, y = j;
        }
    }
    if(!(~x)) {
        puts("YES\n 1");
        return 0;
    }
    auto dfs = [&](auto &&f, int v, int par) -> int {
        for (auto &&i : G[v]) {
            if(i != par){
                if(c[v] != c[i] && par != -1) return 0;
                if(!f(f, i, v)) return 0;
            }
        }
        return 1;
    };
    if(dfs(dfs, x, -1)){
        puts("YES");
        cout << x+1 << "\n";
        return 0;
    }
    if(dfs(dfs, y, -1)){
        puts("YES");
        cout << y+1 << "\n";
        return 0;
    }
    puts("NO");
    return 0;
}