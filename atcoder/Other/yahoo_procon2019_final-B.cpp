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
    int m;
    cin >> m;
    vector<vector<int>> B(m);
    for (int i = 0; i < m-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        B[a-1].emplace_back(b-1);
        B[b-1].emplace_back(a-1);
    }
    vector<int> db = dfs(0, B);
    p = static_cast<int>(max_element(db.begin(), db.end()) - db.begin());
    vector<int> dd = dfs(p, B);
    q = static_cast<int>(max_element(dd.begin(), dd.end()) - dd.begin());
    db = dfs(q, B);
    for (int i = 0; i < m; ++i) {
        db[i] = max(db[i], dd[i]);
        Dmax = max(Dmax, db[i]);
    }
    sort(da.begin(), da.end());
    vector<ll> sa(n+1);
    for (int i = 0; i < n; ++i) {
        sa[i+1] = sa[i] + da[i];
    }
    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        int b = db[i] + 1;
        int cur = upper_bound(da.begin(), da.end(), Dmax - b) - da.begin();
        ans += (ll)cur*Dmax + sa[n]-sa[cur]+(ll)(n-cur)*b;
    }
    cout << ans << "\n";
    return 0;
}
