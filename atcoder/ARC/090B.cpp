#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T>
class WeightedUnionFind {
    vector<int> uni;
    vector<T> weights;
    int n;
public:
    explicit WeightedUnionFind(int n, T SUM_UNITY = 0) :
    uni(static_cast<u32>(n), -1) , n(n), weights(n,  SUM_UNITY){};

    int root(int a) {
        if (uni[a] < 0) return a;
        else {
            int r = root(uni[a]);
            weights[a] += weights[uni[a]];
            return (uni[a] = r);
        }
    }

    bool unite(int a, int b, T w) {
        w += weight(a); w -= weight(b);
        a = root(a);
        b = root(b);
        if(a == b) return false;
        if(uni[a] > uni[b]) swap(a, b), w = -w;
        uni[a] += uni[b];
        uni[b] = a;
        weights[b] = w;
        return true;
    }

    int size(int a){
        return -uni[root(a)];
    }

    T weight(T a){
        root(a);
        return weights[a];
    }
    int diff(int x, int y){
        return weight(y) - weight(x);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    WeightedUnionFind<int> un(n);
    for (int i = 0; i < m; ++i) {
        int l, r, d;
        scanf("%d%d%d", &l, &r, &d);
        if (un.root(l-1) == un.root(r-1)){
            if(un.diff(l-1, r-1) != d){
                cout << "No" << "\n";
                return 0;
            }
        }else {
            un.unite(l-1, r-1, d);
        }
    }
    cout << "Yes\n";
    return 0;
}
