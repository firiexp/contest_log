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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }


template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ", ";
        os << v[i];
    }
    return os << "}";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "{" << p.first << ", " << p.second << "}";
}

int main() {
    int n;
    cin >> n;
    vector<array<ll, 3>> cost(n);
    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &cost[i][j]);
        }
    }
    vector<vector<int>> G(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    int root = -1;
    for (int i = 0; i < n; ++i) {
        if(G[i].size() >= 3) {
            puts("-1");
            return 0;
        } else if(G[i].size() == 1){
            root = i;
        }
    }
    vector<int> Q(n);
    stack<int> s;
    int cnt = 0;
    vector<int> visited(n, 0), num(n);
    s.emplace(root);
    while(!s.empty()){
        int a = s.top(); s.pop();
        visited[a]++;
        Q[cnt] = a;
        num[a] = cnt++;
        for (auto &&i : G[a]) {
            if(!visited[i]) s.emplace(i);
        }
    }
    ll ans = INF<ll>;
    vector<int> ansv;
    vector<int> perm{0, 1, 2};
    vector<int> anss(n);
    do {
        ll S = 0;
        vector<int> ansss(n);
        for (int i = 0; i < n; ++i) {
            S += cost[Q[i]][perm[i%3]];
            ansss[Q[i]] = perm[i%3];
        }
        if(ans > S){
            ans = S;
            anss = ansss;
        }
    }while(next_permutation(perm.begin(),perm.end()));
    printf("%lld\n", ans);
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%d", anss[i]+1);
    }
    puts("");
    return 0;
}