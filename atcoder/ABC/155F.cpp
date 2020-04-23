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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

class UnionFind {
    int n;
    vector<int> uni;
    int forest_size;
public:
    explicit UnionFind(int n) : n(n), uni(static_cast<u32>(n), -1), forest_size(n) {};

    int root(int a){
        if (uni[a] < 0) return a;
        else return (uni[a] = root(uni[a]));
    }

    bool unite(int a, int b) {
        a = root(a);
        b = root(b);
        if(a == b) return false;
        if(uni[a] > uni[b]) swap(a, b);
        uni[a] += uni[b];
        uni[b] = a;
        forest_size--;
        return true;
    }
    int size(){ return forest_size; }
    int size(int i){ return -uni[root(i)]; }
    bool same(int a, int b) { return root(a) == root(b); }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &A[i].first, &A[i].second);
    }
    sort(A.begin(),A.end());
    vector<tuple<int, int, int>> query;
    UnionFind uf(n+1);
    vector<vector<pair<int, int>>> G(n+1);
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        auto x = lower_bound(A.begin(),A.end(), make_pair(l, 0))-A.begin();
        auto y = upper_bound(A.begin(),A.end(), make_pair(r, INF<int>))-A.begin()-1;
        if(x <= y){
            G[x].emplace_back(y+1, i);
            G[y+1].emplace_back(x, i);
            query.emplace_back(x, y+1, i);
            uf.unite(x, y+1);
        }
    }
    vector<int> S(n+1);
    vector<int> cnt(n+1);
    S[0] = A[0].second;
    for (int i = 0; i < n; ++i) {
        if(i){
            S[i] = A[i-1].second^A[i].second;
        }
    }
    S[n] = A[n-1].second;
    for (int i = 0; i <= n; ++i) {
        cnt[uf.root(i)] += S[i];
    }
    for (int i = 0; i <= n; ++i) {
        if(uf.root(i) == i && cnt[i]%2) {
            puts("-1");
            return 0;
        }
    }
    vector<int> visited(n+1), par(n+1), edge(n+1);
    queue<int> Q;
    deque<int> Q2;
    vector<int> ans;
    for (int i = 0; i <= n; ++i) {
        if(uf.root(i) == i){
            Q.emplace(i); Q2.emplace_front(i);
            visited[i] = 1;
            while(!Q.empty()){
                auto p = Q.front(); Q.pop();
                for (auto &&j : G[p]) {
                    if(!visited[j.first]){
                        edge[j.first] = j.second;
                        visited[j.first] = 1;
                        Q.emplace(j.first);
                        Q2.emplace_front(j.first);
                        par[j.first] = p;
                    }
                }
            }
            for (auto &&p : Q2) {
                if(S[p]&1){
                    ans.emplace_back(edge[p]);
                    S[par[p]] ^= 1;
                    S[p] = 0;
                }
            }
            Q2.clear();
        }
    }
    cout << ans.size() << "\n";
    sort(ans.begin(),ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        if(i) printf(" ");
        printf("%d", ans[i]+1);
    }
    puts("");
    return 0;
}