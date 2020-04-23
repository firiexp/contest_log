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

template<class G>
class SWAG {
    using T = typename G::T;
    vector<T> in, out, insum, outsum;
public:
    SWAG() : in(0), out(0), insum(1, G::e()), outsum(1, G::e()) {}

    void push(const T& v){
        insum.push_back(G::f(insum.back(), v));
        in.push_back(v);
    }

    void pop(){
        if(out.empty()){
            do {
                out.emplace_back(in.back());
                outsum.emplace_back(G::f(in.back(), outsum.back()));
                in.pop_back(); insum.pop_back();
            }while(!in.empty());
        }
        out.pop_back(); outsum.pop_back();
    }

    T fold(){
        return G::f(outsum.back(), insum.back());
    }

    int size(){
        return in.size()+out.size();
    }
};

struct Monoid {
    using T = int;
    static T f(T a, T b) { return min(a, b); }
    static T e() { return INF<int>; }
};

int main() {
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        uf.unite(a-1, b-1);
    }
    vector<int> cnt(n+1);
    for (int i = 0; i < n; ++i) {
        if(uf.root(i) == i) cnt[uf.size(i)]++;
    }
    vector<int> ans(n+1, INF<int>);
    ans[0] = 0;
    SWAG<Monoid> Q;
    for (int i = 1; i <= n; ++i) {
        if(cnt[i]){
            for (int x = 0; x < i; ++x) { // j mod x
                for (int j = 0; i*j+x <= n; ++j) {
                    Q.push(ans[j*i+x]-j);
                    ans[j*i+x] = Q.fold()+j;
                    if(Q.size() > cnt[i]) Q.pop();
                }
                while(Q.size()) Q.pop();
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if(ans[i] == INF<int>) puts("-1");
        else printf("%d\n", ans[i]-1);
    }
    return 0;
}