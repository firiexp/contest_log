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

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    vector<int> indeg(n), visited(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d",  &a, &b);
        G[a-1].emplace_back(b-1);
        indeg[b-1]++;
    }

    int ok = 1;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if(indeg[i] == 0 && !visited[i]){
            queue<int> Q;
            Q.emplace(i);
            visited[i] = 1;
            while(!Q.empty()){
                int x = Q.front(); Q.pop();
                ans.emplace_back(x);
                for (auto &&y : G[x]) {
                    visited[y] = visited[x]+1;
                    if(visited[y] == n) ok = 0;
                    indeg[y]--;
                    if(!indeg[y]) Q.emplace(y);
                }
            }
        }
    }
    for (auto &&j : ans) {
        printf("%d\n", j+1);
    }
    printf("%d\n", ok);
    return 0;
}