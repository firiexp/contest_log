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


class IndependentSet {
    int n;
    vector<vector<int>> G;
    void dfs(int x, vector<bool> &visited, vector<bool> &gcan, vector<bool> &alive){
        stack<int> s;
        s.emplace(x);
        while(!s.empty()){
            int y = s.top();
            visited[y] = true;
            gcan[y] = true;
            s.pop();
            for (auto &&i : G[y]) {
                if(!visited[i] && alive[i]) s.emplace(i);
            }
        }
    }

    int ConnectedCase(vector<bool> can) {
        int pMax = -1, pMin = -1, Max = -1, Min = n+1, num = 0;
        for (int i = 0; i < n; ++i) {
            if(!can[i]) continue;
            ++num;
            int tnum = 0;
            for (auto &&j : G[i]) if(can[j]) ++tnum;
            if(Max < tnum) Max = tnum, pMax = i;
            if(Min > tnum) Min = tnum, pMin = i;
        }
        if(num == 1) return 1;
        if(Max <= 2){
            if(Min == 1) return (num+1)/2;
            else return num/2;
        }
        int ans = 0;
        vector<bool> ncan = can;
        if(Min < 2){
            ncan[pMin] = false;
            for (auto &&i : G[pMin]) ncan[i] = false;
            ans = max(ans, GeneralCase(ncan) + 1);
        }else {
            ncan[pMax] = false;
            for (auto &&i : G[pMax]) ncan[i] = false;
            int temp = GeneralCase(ncan);
            ans = max(ans, temp+1);
            ncan = can;
            ncan[pMax] = false;
            ans = max(ans, GeneralCase(ncan));
        }
        return ans;
    }

    int GeneralCase(vector<bool> alive) {
        if(n <= 1) return n;
        vector<bool> visited(n, 0);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if(!visited[i] && alive[i]){
                vector<bool> gcan(n, false);
                dfs(i, visited, gcan, alive);
                res += ConnectedCase(gcan);
            }
        }
        return res;
    }
public:
    explicit IndependentSet(int n): n(n), G(n) {}
    void add_edge(int u, int v){
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    int stable_set() {
        vector<bool> alive(n, true);
        return GeneralCase(alive);
    }
};

int main() {
    int n, m;
    while(cin >> n >> m, n){
        vector<vector<int>> v(m, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> v[j][i];
            }
        }
        IndependentSet G(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                if(i == j) continue;
                vector<pair<int, int>> u(n);
                for (int k = 0; k < n; ++k) u[k] = {v[i][k], v[j][k]};
                sort(u.begin(),u.end());
                int ok = 1;
                for (int k = 1; k < n; ++k) {
                    if(u[k].second < u[k-1].second) ok = 0;
                }
                if(!ok){
                    G.add_edge(i, j);
                }
            }
        }
        cout << G.stable_set() << "\n";
    }
    return 0;
}