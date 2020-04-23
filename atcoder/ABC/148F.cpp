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
    int n, a, b;
    cin >> n >> a >> b;
    a--; b--;
    swap(a, b);
    vector<vector<int>> G(n);
    for (int i = 0; i < n-1; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--; y--;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    vector<vector<int>> G2(n);
    vector<int> dep(n), par(n);
    auto dfs = [&](int x, int p, auto &&f) -> void {
        for (auto &&i : G[x]) {
            if(i != p){
                G2[x].emplace_back(i);
                par[i] = x;
                f(i, x, f);
            }
        }
    };
    dfs(a, -1, dfs);
    vector<int> dp(n);
    auto ff = [&](int x, int val, auto &&f) -> int {
        dep[x] = val;
        int a = 0;
        for (auto &&i : G2[x]) {
            a = max(a, f(i, val+1, f));
        }
        dp[x] = a;
        return a+1;
    };
    ff(a, 0, ff);
    int aa = dep[b]/2, bb = dep[b]-aa;
    {
        int c = b;
        for (int i = 0; i < bb; ++i) {
            c = par[c];
        }
        a = c;
    }
    for (int i = 0; i < aa; ++i) {
        b = par[b];
    }
    cout << dp[b]+bb-1 << "\n";
    return 0;
}