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

struct edge {
    int from, to; ll c, d;
    edge(int to, ll c, ll d) : from(-1), to(to), c(c), d(d) {}
};


int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n-2);
    for (auto &&i : v) scanf("%d", &i);
    vector<vector<edge>> G(n);
    for (int i = 0; i < m; ++i) {
        int a, b; ll c, d;
        scanf("%d %d %lld %lld", &a, &b, &c, &d);
        if(b != 1 && b != n) c += v[b-2];
        G[a-1].emplace_back(b-1, c, d);
        if(b != 1 && b != n) c -= v[b-2];
        if(a != 1 && a != n) c += v[a-2];
        G[b-1].emplace_back(a-1, c, d);
        if(a != 1 && a != n) c -= v[a-2];
    }
    vector<ll> d(n, INF<ll>);
    priority_queue<pair<ll, int>,vector<pair<ll, int>>,greater<>> Q;
    d[0]=0;
    Q.emplace(0,0);
    while(!Q.empty()){
        ll cost; int i;
        tie(cost, i) = Q.top(); Q.pop();
        if(d[i] < cost) continue;
        for (auto &&e : G[i]) {
            auto cost2 = (cost+e.d-1)/e.d*e.d + e.c;
            if(d[e.to] <= cost2) continue;
            d[e.to] = cost2;
            Q.emplace(d[e.to], e.to);
        }
    }
    cout << (d[n-1] <= k ? d[n-1] : -1LL) << "\n";
    return 0;
}