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
    vector<vector<pair<ll, ll>>> G(n);
    for (int i = 0; i < m; ++i) {
        ll u, v; ll s;
        cin >> u >> v >> s;
        G[u-1].emplace_back(v-1, s);
        G[v-1].emplace_back(u-1, s);
    }
    vector<pair<ll, ll>> v(n, make_pair(0, 0));
    v[0] = make_pair(1, 0);
    pair<ll, ll> s {0, 0};
    queue<ll> q;
    q.emplace(0);
    while(!q.empty()){
        ll f = q.front(); q.pop();
        for (auto &&i : G[f]) {
            ll to, cost; tie(to, cost) = i;
            if(v[to].first == 0) {
                q.emplace(to);
                v[to] = make_pair(-v[f].first, cost-v[f].second);
            }else if(v[to].first != v[f].first){
                if(v[to].second != cost-v[f].second){
                    puts("0");
                    return 0;
                }
            }else {
                ll x = (cost-v[to].second-v[f].second);
                if((x+INF<ll>+1)%2 || x/(2*v[f].first) <= 0){
                    puts("0");
                    return 0;
                }else {
                    s = make_pair(2, x/(2*v[f].first));
                    while(!q.empty()) q.pop();
                    break;
                }
            }
        }
    }
    if(s == make_pair(0LL, 0LL)){
        ll a = 0, b = INF<ll>;
        for (int i = 0; i < n; ++i) {
            if(v[i].first > 0) a = max(a, -v[i].second);
            else b = min(b, v[i].second);
        }
        cout << max(b-a-1, 0LL) << "\n";
    }else {
        vector<ll> va(n, 0);
        va[0] = s.second;
        q.emplace(0);
        bool valid = true;
        while(!q.empty()){
            ll f = q.front(); q.pop();
            for (auto &&i : G[f]) {
                ll to, cost; tie(to, cost) = i;
                if(va[to]){
                    if(va[to]+va[f] != cost) valid = false;
                }else {
                    if(cost-va[f] <= 0) {
                        valid = false;
                    }else {
                        va[to] = cost - va[f];
                        q.emplace(to);
                    }
                }
            }
        }
        puts(valid ? "1" : "0");
    }
    return 0;
}
