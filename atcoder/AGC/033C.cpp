#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

vector<int> dfs(int i, vector<vector<int>> &G){
    auto n = G.size();
    vector<int> dist(n);
    stack<pair<int, int>> s;
    int cnt = 0;
    vector<int> visited(n, 0);
    s.emplace(i, 0);
    while(!s.empty()){
        int a, d; tie(a, d) = s.top(); s.pop();
        visited[a]++;
        dist[a] = d;
        for (auto &&j : G[a]) {
            if(!visited[j]) s.emplace(j, d+1);
        }
    }
    return dist;
}


int main() {
    int Dmax = 0;
    int n;
    cin >> n;
    vector<vector<int>> A(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        A[a-1].emplace_back(b-1);
        A[b-1].emplace_back(a-1);
    }
    vector<int> da = dfs(0, A);
    int p = static_cast<int>(max_element(da.begin(), da.end()) - da.begin());
    vector<int> dc = dfs(p, A);
    int q = static_cast<int>(max_element(dc.begin(), dc.end()) - dc.begin());
    da = dfs(q, A);
    for (int i = 0; i < n; ++i) {
        da[i] = max(da[i], dc[i]);
        Dmax = max(Dmax, da[i]);
    }
    cout << (Dmax%3 == 1 ? "Second" : "First") << "\n";
    return 0;
}
