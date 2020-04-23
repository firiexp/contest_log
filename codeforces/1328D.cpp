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

void solve(){
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int t = -1, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if(v[i] == v[(i+1)%n]) t = (i+1)%n, cnt++;
    }
    if(cnt == n){
        puts("1");
        for (int i = 0; i < n; ++i) {
            if(i) printf(" ");
            printf("%d", 1);
        }
        puts("");
    }else if(t == -1 && n%2){
        puts("3");
        for (int i = 0; i < n; ++i) {
            if(i) printf(" ");
            if(i != n-1) printf("%d", (i&1)+1);
            else printf("%d", 3);
        }
        puts("");
    }else {
        int p = 1;
        puts("2");
        for (int i = 0; i < n; ++i) {
            if(n%2 && t == i){
                p = 3-p;
            }
            if(i) printf(" ");
            printf("%d", p);
            p = 3-p;
        }
        puts("");
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}