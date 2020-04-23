#include <iostream>
#include <algorithm>
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

void solve(int h, int w){
    array<int, 4> dx{-1, 1, 0, 0}, dy{0, 0, -1, 1};
    vector<vector<int>> v(h+2, vector<int>(w+2, -1));
    int sy, sx, gy, gx;
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            if(s[j] == 'X') v[i+1][j+1] = 1000;
            else if(s[j] == '#' || s[j] == 'S') v[i+1][j+1] = -1;
            else v[i+1][j+1] = 0;
            if(s[j] == 'S') sy = i+1, sx = j+1;
            else if(s[j] == 'G') gy = i+1, gx = j+1;
        }
    }
    vector<int> M{0};
    for (int i = 0, cur = 1; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(v[i+1][j+1] == 1000){
                queue<pair<int, int>> Q;
                Q.emplace(i+1, j+1);
                M.emplace_back();
                v[i+1][j+1] = cur;
                while(!Q.empty()){
                    M.back()++;
                    int y, x; tie(y, x) = Q.front(); Q.pop();
                    for (int k = 0; k < 4; ++k) {
                        if(v[y+dy[k]][x+dx[k]] == 1000){
                            v[y+dy[k]][x+dx[k]] = cur;
                            Q.emplace(y+dy[k], x+dx[k]);
                        }
                    }
                }
                M.back() /= 2;
                cur++;
            }
        }
    }
    for (int ans = abs(sx-gx)+abs(sy-gy); ; ++ans) {
        auto G = v;
        vector<int> m(M.size());
        auto dfs = [&](int y, int x, int dep, auto &&f) -> bool {
            if(gy == y && gx == x) return true;
            if(dep+abs(gy-y)+abs(gx-x) > ans) return false;
            for (int k = 0; k < 4; ++k) {
                int p = G[y+dy[k]][x+dx[k]];
                if(p == 0){
                    G[y+dy[k]][x+dx[k]] = -1;
                    if(f(y+dy[k], x+dx[k], dep+1, f)) return true;
                    G[y+dy[k]][x+dx[k]] = 0;
                }else if(p > 0 && m[p]+1 <= M[p]){
                    m[p]++;
                    G[y+dy[k]][x+dx[k]] = -1;
                    if(f(y+dy[k], x+dx[k], dep+1, f)) return true;
                    G[y+dy[k]][x+dx[k]] = p;
                    m[p]--;
                }
            }
            return false;
        };
        if(dfs(sy, sx, 0, dfs)){
            cout << ans << "\n";
            return;
        }
    }


}

int main() {
    int h, w;
    while(cin >> w >> h, h){
        solve(h, w);

    }
    return 0;
}