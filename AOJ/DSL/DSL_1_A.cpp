#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

/* initialize */
class DisjointSet {
public:
    vector<int>rank, p; // rank : データの階層, p[i]: 要素iの親
    DisjointSet() = default;;

    explicit DisjointSet(int size){
        rank.resize(static_cast<unsigned int>(size), 0);
        p.resize(static_cast<unsigned int>(size), 0);
        for (int i = 0; i < size; ++i) makeSet(i);

    }

    void makeSet(int i) {
        p[i] = i;
        rank[i] = 0;
    }

    bool same(int x, int y){
        return findSet(x) == findSet(y);
    }

    void unite (int x, int y){
        link(findSet(x), findSet(y));
    }

    void link(int x, int y){
        if (rank[x] > rank[y]){
            p[y] = x;
        } else {
            p[x] = y;
            if(rank[x] == rank[y]) rank[y]++;
        }
    }

    int findSet(int x){
        if (x != p[x]){
            p[x] = findSet(p[x]);
        }
        return p[x];
    }
};
/* main */
int main() {
    int n, a, b,q;
    int t;
    cin >> n >> q;
    DisjointSet ds = DisjointSet(n);
    for (int i = 0; i < q; ++i) {
        cin >> t >> a >> b;
        if (t == 0) ds.unite(a, b);
        else if (t == 1) {
            if (!ds.same(a, b)) cout << 0 << "\n";
            else cout << 1 << "\n";
        }
    }
    return 0;
}