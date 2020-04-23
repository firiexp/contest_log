#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> edges(n);
    vector<pair<int, int>> v;
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].emplace_back(b);
        edges[b].emplace_back(a);
        v.emplace_back(a, b);
    }
    int ans = INF<int>;
    for (int i = 0; i < n-k%2; ++i) {
        stack<pair<int, int>> S;
        vector<int> dist(n, INF<int>);
        if(k % 2 == 0) S.emplace(i, 0);
        else {
            S.emplace(v[i].first, 0);
            S.emplace(v[i].second, 0);
        }
        int p = 0;
        while(!S.empty()){
            int x, c;
            tie(x, c) = S.top(); S.pop();
            for (auto &&j : edges[x]) {
                if(c+1 < dist[j]) S.emplace(j, c+1);
            }
            dist[x] = min(dist[x], c);
        }
        for (int j = 0; j < n; ++j) {
            if(dist[j] > k/2) p++;
        }
        ans = min(ans, p);
    }
    cout << ans << "\n";
    return 0;
}
