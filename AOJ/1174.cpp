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

namespace ICPC {
    array<array<int, 12>, 12> G{}, visited{};
    int h, w, c;
    int ans = 0;

    void dfs(int depth){
        for (int i = 1; i <= 6; ++i) {
            int color = G[1][1];
            if(color == i) continue;
            queue<pair<int, int>> Q;
            Q.emplace(1, 1);
            array<int, 4> di{-1, 1, 0, 0}, dj{0, 0, 1, -1};
            vector<pair<int, int>> v;
            G[1][1] = i;
            while(!Q.empty()){
                auto p = Q.front(); Q.pop();
                v.emplace_back(p);
                int y, x; tie(y, x) = p;
                for (int k = 0; k < 4; ++k) {
                    if(G[y+di[k]][x+dj[k]] == color){
                        G[y+di[k]][x+dj[k]] = i;
                        Q.emplace(y+di[k], x+dj[k]);
                    }
                }
            }
            if(depth == 4 && i == c) {
                for (int j = 0; j < h; ++j) {
                    for (int k = 0; k < w; ++k) {
                        visited[j+1][k+1] = 0;
                    }
                }
                int cnt = 0;
                Q.emplace(1, 1);
                while(!Q.empty()){
                    auto p = Q.front(); Q.pop();
                    int y, x; tie(y, x) = p;
                    visited[y][x] = 1;
                    cnt++;
                    for (int k = 0; k < 4; ++k) {
                        if(G[y+di[k]][x+dj[k]] == i && !visited[y+di[k]][x+dj[k]]){
                            Q.emplace(y+di[k], x+dj[k]);
                            visited[y+di[k]][x+dj[k]] = 1;
                        }
                    }
                }
                ans = max(ans, cnt);
            }else if(depth <= 3) {
                dfs(depth+1);
            }
            for (auto &&j : v) {
                G[j.first][j.second] = color;
            }
        }
    }

    void solve(int H, int W, int C){
        h = H, w = W, c = C;
        for (int i = 0; i <= h+1; ++i) {
            for (int j = 0; j <= w+1; ++j) {
                G[i][j] = -1;
            }
        }
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                cin >> G[i][j];
            }
        }
        ans = 0;
        dfs(0);
        cout << ans << "\n";
    }
}

int main() {
    int h, w, c;
    while(cin >> h >> w >> c, h){
        ICPC::solve(h, w, c);
    }
    return 0;
}