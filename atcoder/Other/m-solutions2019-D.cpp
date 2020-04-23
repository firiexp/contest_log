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
    vector<pair<int, int>> v(n-1);
    vector<vector<int>> G(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        v[i] = make_pair(a, b);
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    vector<int> c(n);
    for (auto &&i : c) scanf("%d", &i);
    sort(c.begin(),c.end());
    vector<int> ans(n);
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
            if(!visited[i]) s.emplace(i);
        }
    }
    cnt = 0;
    for (int i = 0; i < n; ++i) {
        ans[Q.front()] = c[cnt++];
        Q.pop_front();
    }
    ll a = 0;
    for (auto &&j : v) {
        a += min(ans[j.first], ans[j.second]);
    }
    cout << a << "\n";
    for (int i = 0; i < n; ++i) {
        if(i) cout << " ";
        cout << ans[i];
    }
    puts("");
    return 0;
}