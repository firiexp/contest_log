#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> in(n, 0);
    vector<vector<int>> G(n);
    for (int i = 0; i < n-1+m; ++i) {
        int a, b;
        cin >> a >> b;
        G[a-1].emplace_back(b-1);
        in[b-1]++;
    }
    vector<int> visited(n, 0);
    vector<int> ans(n, -1);
    int par = -1;
    for (int i = 0; i < n; ++i) {
        if(in[i] == 0) par = i;
    }
    deque<int> d;
    d.emplace_back(par);
    while(!d.empty()){
        int p = d.front(); d.pop_front();
        if(visited[p]) continue;
        visited[p] = 1;
        for (auto &&i : G[p]) {
            ans[i] = p;
            if(in[i] == 1) d.emplace_back(i);
            in[i]--;
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\n", ans[i]+1);
    }
    return 0;
}
