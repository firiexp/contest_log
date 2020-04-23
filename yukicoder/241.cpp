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

class Bipartite_Matching {
    vector<vector<int>> G;
    vector<int> used, alive;
    int t;
public:
    vector<int> match;
    explicit Bipartite_Matching(int n): t(0), G(n), used(n, 0), alive(n, -1), match(n, -1) {};

    void add_edge(int a, int b){
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    bool dfs(int x){
        used[x] = t;
        for (auto &&i : G[x]) {
            int w = match[i];
            if(alive[i] == 0) continue;
            if(w == -1 || (used[w] != t && dfs(w))){
                match[x] = i;
                match[i] = x;
                return true;
            }
        }
        return false;
    }

    int matching() {
        int ans = 0;
        for (int i = 0; i < G.size(); ++i) {
            if(alive[i] == 0) continue;
            if(match[i] == -1) {
                ++t;
                ans += dfs(i);
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    Bipartite_Matching G(2*n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < n; ++j) {
            if(j != x){
                G.add_edge(i, j+n);
            }
        }
    }
    if(G.matching() != n){
        puts("-1");
    }else {
        for (int i = 0; i < n; ++i) {
            cout << G.match[i]-n << "\n";
        }
    }
    return 0;
}