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


template <class K, class V>
class RadixHeap {
    static constexpr int bit_length = sizeof(K)*8;
    K last;
    size_t sz, cnt;
    RadixHeap() : last(0), sz(0), cnt(0) {}
    array<vector<pair<K, V>>, bit_length> v;
    static inline int bsr(int x){
        return x ? bit_length-__builtin_clz(x) : 0;
    }
    static inline int bsr(ll x){
        return x ? bit_length-__builtin_clzll(x) : 0;
    }

    void pull() {
        if(cnt < v[0].size()) return;;
        int i = 1;
        while(v[i].empty()) i++;
        last = min_element(v[i].begin(),v[i].end())->first;
        for (auto &&x : v[i]) v[bsr(x.first ^ last)].push_back(x);
        v[i].clear();
    }
public:
    void emplace(K x, V val){
        sz++;
        v[bsr(x^last)].emplace_back(x, val);
    }

    pair<K, V> top() {
        pull();
        return v[0][cnt];
    }

    void pop() {
        pull();
        sz--;
        cnt++;
    }

    size_t size() const { return sz; }
    bool empty() const { return !sz; }
};


int main() {
    int n, m, l;
    cin >> n >> m >> l;
    using P = pair<int, int>;
    vector<vector<P>> G(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--; b--;
        if(c <= l){
            G[a].emplace_back(b, c);
            G[b].emplace_back(a, c);
        }
    }
    constexpr ll M = ((ll)INF<int> << 31) + INF<int>;
    vector<vector<ll>> ans(n, vector<ll>(n, M));
    for (int i = 0; i < n; ++i) {
        ans[i][i] = 0;
        RadixHeap<ll, int> Q;
        Q.emplace(0, i);
        ll mask = (1LL << 31)-1;
        while(!Q.empty()){
            ll p; int x;
            tie(p, x) = Q.top(); Q.pop();
            if(ans[i][x] < p) continue;
            for (auto &&e : G[x]) {
                auto cost2 = p + e.second;
                if((cost2 & mask) > l){
                    cost2 = (((p >> 31) + 1) << 31) + e.second;
                }
                if(ans[i][e.first] <= cost2) continue;
                ans[i][e.first] = cost2;
                Q.emplace(ans[i][e.first], e.first);
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        cout << (ans[s][t] == M ? -1 : ans[s][t] >> 31) << "\n";
    }
    return 0;
}