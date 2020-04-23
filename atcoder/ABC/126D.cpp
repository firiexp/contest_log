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

template <typename T>
struct edge {
    int from, to;
    T cost;

    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}

    explicit operator int() const {return to;}
};


int main() {
    int n;
    cin >> n;
    vector<vector<edge<int>>> G(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        G[u].emplace_back(v, w&1);
        G[v].emplace_back(u, w&1);
    }
    deque<int> Q;
    stack<int> s;
    int cnt = 0;
    vector<int> visited(n, 0), num(n);
    s.emplace(0);
    vector<int> dp(n);
    while(!s.empty()){
        int a = s.top(); s.pop();
        visited[a]++;
        num[a] = cnt++;
        Q.emplace_front(a);
        for (auto &&i : G[a]) {
            if(!visited[i.to]) {
                dp[i.to] = dp[a]^i.cost;
                s.emplace(i.to);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\n", dp[i]);
    }
    return 0;
}