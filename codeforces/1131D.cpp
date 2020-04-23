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
    vector<vector<int>> G(n+m);
    vector<string> S(n);
    for (int i = 0; i < n; ++i) {
        cin >> S[i];
    }
    UnionFind uf(n+m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(S[i][j] == '=') uf.unite(i, n+j);
        }
    }
    vector<int> indeg(n+m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int A = uf.root(i), B = uf.root(n+j);
            if(S[i][j] == '<'){
                if(A == B){
                    puts("No");
                    return 0;
                }
                G[A].emplace_back(B);
                indeg[B]++;
            }else if(S[i][j] == '>') {
                if(A == B){
                    puts("No");
                    return 0;
                }
                G[B].emplace_back(A);
                indeg[A]++;
            }
        }
    }
    vector<int> ans(n+m, 1);
    queue<int> Q;
    for (int i = 0; i < n+m; ++i) {
        if(indeg[i] == 0 && uf.root(i) == i) Q.emplace(i);
    }
    while(!Q.empty()){
        int i = Q.front(); Q.pop();
        for (auto &&j : G[i]) {
            ans[j] = max(ans[j], ans[i]+1);
            indeg[j]--;
            if(!indeg[j]) Q.emplace(j);
        }
    }
    for (int i = 0; i < n+m; ++i) {
        if(indeg[i]) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%d", ans[uf.root(i)]);
    }
    puts("");
    for (int i = 0; i < m; ++i) {
        if(i) printf(" ");
        printf("%d", ans[uf.root(i+n)]);
    }
    puts("");
    return 0;
}