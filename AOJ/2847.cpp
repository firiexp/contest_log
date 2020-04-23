
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
    int n;
    cin >> n;
    vector<vector<int>> g(n+2, vector<int> (n+2, 0));
    auto h = g;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            g[i+1][j+1] = 1;
        }
    }
    array<int, 4> di = {1, 0, -1, 0}, dj = {0, 1, 0, -1};
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 0; k < 4; ++k) {
                h[i][j] += g[i+di[k]][j+dj[k]];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            g[i+1][j+1] = 0;
        }
    }
    vector<int> v(n*n);
    int M = 2*(n*n-n);
    vector<int> a(M), b(M);
    vector<vector<int>> G(n*n);
    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        v[a[i]]++; v[b[i]]++;
        G[a[i]].emplace_back(b[i]);
        G[b[i]].emplace_back(a[i]);
    }
    int cur = 0;
    for (int i = 0; i < n*n; ++i) {
        if(v[i] == 2) cur = i;
    }
    g[1][1] = cur+1;
    v[cur] = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(g[i+1][j+1]) for (int to : G[g[i+1][j+1]-1]) {
                for (int k = 0; k < 2; ++k) {
                    int y = i+di[k]+1, x = j+dj[k]+1;
                    if(!g[y][x] && v[to] == h[y][x]){
                        g[y][x] = to+1;
                        v[to] = -1;
                    }
                }
            }

        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(j) cout << " ";
            cout << g[i+1][j+1];
        }
        puts("");
    }
    return 0;
}