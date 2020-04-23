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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> G(n);
    vector<int> deg(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        G[a].emplace_back(b, i);
        G[b].emplace_back(a, i);
    }
    vector<int> ans(n-1);
    auto dfs = [&](int i, int par, int col, auto &&f) -> void {
        int cnt = 1;
        for (auto &&j : G[i]) {
            if(j.first == par) continue;
            if(cnt == col) cnt++;
            ans[j.second] = cnt;
            f(j.first, i, cnt, f);
            cnt++;
        }
    };
    dfs(0, -1, -1, dfs);
    cout << *max_element(ans.begin(),ans.end()) << "\n";
    for (int i = 0; i < n-1; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}