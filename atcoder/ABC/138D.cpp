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
    int n, q;
    cin >> n >> q;
    vector<vector<int>> G(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    vector<int> dp(n);
    for (int i = 0; i < q; ++i) {
        int p, x; scanf("%d %d", &p, &x);
        dp[p-1] += x;
    }
    deque<int> Q;
    stack<int> s;
    int cnt = 0;
    vector<int> visited(n, 0), num(n);
    s.emplace(0);
    while(!s.empty()){
        int a = s.top(); s.pop();
        visited[a]++;
        num[a] = cnt++;
        Q.emplace_front(a);
        for (auto &&i : G[a]) {
            if(!visited[i]) {
                s.emplace(i);
                dp[i] += dp[a];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if(i) cout << " ";
        cout << dp[i];
    }
    puts("");
    return 0;
}