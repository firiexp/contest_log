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
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    UnionFind uf(2*n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        uf.unite(a, b+n); uf.unite(a+n, b);
    }
    vector<vector<int>> no(3);
    for (int i = 1; i <= n; ++i) {
        no[i%3].emplace_back(i);
    }
    vector<int> col(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if(uf.same(0, i)) col[i] = 0;
        else col[i] = 1, cnt++;
    }
    if(cnt < n-cnt){
        cnt = n-cnt;
        for (int i = 0; i < n; ++i) {
            col[i] ^= 1;
        }
    }

    vector<int> ans(n);
    if(cnt <= no[0].size()+no[2].size()){
        for (int i = 0; i < n; ++i) {
            if(col[i] == 1){
                if(!no[2].empty()) {
                    ans[i] = no[2].back();
                    no[2].pop_back();
                }else if(!no[0].empty()) {
                    ans[i] = no[0].back();
                    no[0].pop_back();
                }else {
                    ans[i] = no[1].back();
                    no[1].pop_back();
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if(col[i] == 0){
                if(!no[1].empty()) {
                    ans[i] = no[1].back();
                    no[1].pop_back();
                }else if(!no[0].empty()){
                    ans[i] = no[0].back();
                    no[0].pop_back();
                }else {
                    ans[i] = no[2].back();
                    no[2].pop_back();
                }
            }
        }
    }else {
        for (int i = 0; i < n; ++i) {
            if(col[i] == 1){
                if(!no[2].empty()) {
                    ans[i] = no[2].back();
                    no[2].pop_back();
                }else if(!no[1].empty()) {
                    ans[i] = no[1].back();
                    no[1].pop_back();
                }else {
                    ans[i] = no[0].back();
                    no[0].pop_back();
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if(col[i] == 0){
                if(!no[2].empty()) {
                    ans[i] = no[2].back();
                    no[2].pop_back();
                }else if(!no[1].empty()) {
                    ans[i] = no[1].back();
                    no[1].pop_back();
                }else {
                    ans[i] = no[0].back();
                    no[0].pop_back();
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}