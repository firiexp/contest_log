#include <iostream>
#include <queue>

using ll = long long;
using namespace std;
using P = pair<int, int>;
static const int INF = 1000000;

int main() {
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1 , 1};
    int r, c, sy, sx, gy, gx;
    cin >> r >> c >> sy >> sx >> gy >> gx;
    char m[60][60];
    int dis[60][60];
    fill_n(&dis[0][0], 3600, INF);
    queue<P> Q;
    sy--; sx--; gy--; gx--;
    Q.push({sy,sx});
    dis[sy][sx] = 0;
    for (int i = 0; i < r; ++i) {
        string s;
        cin >> s;

        for (int j = 0; j < c; ++j) {
            m[i][j] = s[j];
        }
    }

    while(!Q.empty()){
        int y = Q.front().first, x = Q.front().second; Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (1 <= nx && nx <= c && 1 <=ny && ny <= r && m[ny][nx] != '#'
            && dis[ny][nx] == INF){
                Q.push({ny, nx});
                dis[ny][nx] = dis[y][x] + 1;
            }
        }

    }

    cout << dis[gy][gx] << "\n";
    return 0;
}
