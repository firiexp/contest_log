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
using PQ = priority_queue<T>;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    sort(v.begin(),v.end());
    vector<pair<int, int>> u(m);
    PQ<int> q;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u[i].second, &u[i].first);
    }
    for (int i = 0; i < n; ++i) {
        q.emplace(v[i]);
    }
    sort(u.begin(),u.end(), greater<>());
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        while(cnt < n && u[i].second){
            q.emplace(u[i].first);
            u[i].second--;
            cnt++;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += q.top(); q.pop();
    }
    cout << ans << "\n";
    return 0;
}