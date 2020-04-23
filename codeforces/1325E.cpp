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

using u32 = uint32_t;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int M = 1000000;
    vector<int> minfactor(M+1, 0);
    vector<int> node(M+1, 0);
    vector<int> st(M+1);
    iota(st.begin(),st.end(), 0);
    int cnt = 1;
    for (int i = 2; i <= M; ++i) {
        if(!minfactor[i]){
            node[i] = cnt++;
            for (int j = i; j <= M; j += i) {
                minfactor[j] = i;
            }
        }
    }
    for (int i = 2; i*i <= M; ++i) {
        if(minfactor[i] == i){
            for (int j = i*i; j <= M; j += i*i) {
                st[j] /= i*i;
            }
        }
    }
    vector<vector<int>> G(cnt);
    for (int i = 0; i < n; ++i) {
        if(st[v[i]] == 1){
            puts("1");
            return 0;
        }
        v[i] = st[v[i]];
        int x = node[minfactor[v[i]]], y = node[v[i]/minfactor[v[i]]];
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    if(v.size() != n){
        puts("2");
        return 0;
    }
    int ans = INF<int>;
    vector<int> visited(cnt);
    vector<int> par(cnt);
    for (int i = 0; i <= 170; ++i) {
        queue<int> Q;
        Q.emplace(i);
        fill(visited.begin(),visited.end(), -1);
        fill(par.begin(),par.end(), -1);
        visited[i] = 0;
        while(!Q.empty()){
            int x = Q.front(); Q.pop();
            for (auto &&y : G[x]) {
                if(visited[y] < 0) {
                    Q.emplace(y);
                    visited[y] = visited[x]+1;
                    par[y] = x;
                }else if(par[x] != y){
                    ans = min(ans, visited[x]+visited[y]+1);
                }
            }
        }
    }
    cout << (ans == INF<int> ? -1 : ans) << "\n";
    return 0;
}