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


class UnionFind {
    vector<int> uni;
    int n;
public:
    explicit UnionFind(int n) : uni(static_cast<u32>(n), -1) , n(n){};

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
        return true;
    }
};


int main() {
    int n, m;
    while(cin >> n >> m, n){
        vector<tuple<int, int, int>> v(m);
        for (int i = 0; i < m; ++i) {
            int s, t, c;
            cin >> s >> t >> c;
            s--; t--;
            v[i] = make_tuple(c, s, t);
        }
        sort(v.begin(),v.end());
        vector<int> e;
        UnionFind uf(n);
        for(auto &&i : v){
            int c, s, t; tie(c, s, t) = i;
            if(uf.unite(s, t)) e.emplace_back(c);
        }
        cout << e[(n-1)/2] << "\n";
    }
    return 0;
}