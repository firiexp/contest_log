#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>

static const int INF = 1000000007;
using ll = long long;
using namespace std;

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        v[a-1][b-1] = 1,  v[b-1][a-1] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if(v[i][j]){
                vector<int> visited(n, 0);
                stack<int> Q;
                Q.push(0);
                while(!Q.empty()){
                    int t = Q.top(); Q.pop();
                    visited[t]++;
                    for (int k = 0; k < n; ++k) {
                        if((min(k, t) != j || max(k, t) != i)&& (!visited[k]) && (v[t][k])){
                            Q.push(k);
                        }
                    }
                }
                for (int l = 0; l < n; ++l) {
                    if(!visited[l]) {ans++; break;}
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
