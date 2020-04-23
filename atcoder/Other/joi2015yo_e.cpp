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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> v(h, vector<int>(w, 0));
    auto visited = v;
    queue<tuple<int, int, int>> Q;
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            if(s[j] != '.') {
                v[i][j] = s[j] - '0';
                Q.emplace(i, j, 1);
                visited[i][j] = 1;
            }
        }
    }
    array<int, 8> dx{1, 1, 1, 0, 0, -1, -1, -1}, dy{1, 0, -1, 1, -1, 1, 0, -1};
    int ans = 0;
    int m = 0;
    stack<pair<int, int>> S;
    while(!Q.empty()){
        int i, j, n; tie(i, j, n) = Q.front(); Q.pop();

        int cnt = 0;
        if(n > m){
            m = n;
            while(!S.empty()){
                int p, q; tie(p, q) = S.top(); S.pop();
                v[p][q] = 0;
            }
        }
        if(!v[i][j]) continue;
        for (int k = 0; k < 8; ++k) {
            if(!v[i+dy[k]][j+dx[k]]) cnt++;
        }
        if(cnt >= v[i][j]){
            S.emplace(i, j);
            ans = max(ans, n);
            for (int k = 0; k < 8; ++k) {
                if(v[i+dy[k]][j+dx[k]] && visited[i+dy[k]][j+dx[k]] < n+1) {
                    visited[i+dy[k]][j+dx[k]] = n+1;
                    Q.emplace(i+dy[k], j+dx[k], n+1);
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}