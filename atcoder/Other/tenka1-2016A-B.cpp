#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

void dfs(int i, vector<ll> &c, vector<vector<int>> &child){
    if(child[i].empty()) return;
    ll a = INF<int>;
    for (auto &&v : child[i]) {
        dfs(v, c, child);
        a = min(a, c[v]);
    }
    for (auto &&v : child[i]) {
        c[v] -= a;
    }
    c[i] += a;
}


int main() {
    u32 n, m;
    cin >> n >> m;
    vector<vector<int>> child(n);
    for (int i = 1; i <= n-1; ++i) {
        int p;
        cin >> p;
        child[p].emplace_back(i);
    }
    vector<int> b(m);
    vector<ll> c(n);
    for (int i = 0; i < m; ++i) {
        int bb, cc;
        cin >> bb >> cc;
        b[i] = bb, c[b[i]] = cc;
    }
    for (auto &&x : child[0]) {
        dfs(x, c, child);
    }
    ll ans = accumulate(c.begin(), c.end(), 0LL);
    cout << ans << "\n";
    return 0;
}
