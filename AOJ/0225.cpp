#include <iostream>
#include <algorithm>
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
    int n;
    while(cin >> n, n){
        array<int, 256> cnt{};
        int a = 0;
        fill(cnt.begin(), cnt.end(), -1);
        vector<int> in(26), out(26);
        UnionFind uf(26);
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            if(!~cnt[s.front()]) cnt[s.front()] = a++;
            if(!~cnt[s.back()]) cnt[s.back()] = a++;
            uf.unite(cnt[s.front()], cnt[s.back()]);
            in[cnt[s.front()]]++;
            out[cnt[s.back()]]++;
        }
        int ok = 1;
        for (int i = 0; i < a; ++i) {
            if(in[i] != out[i]) ok = 0;
        }
        if(uf.size(0) == a && ok) puts("OK");
        else puts("NG");
    }
    return 0;
}