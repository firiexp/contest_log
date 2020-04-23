#include <iostream>
#include <queue>

using ll = long long;
using namespace std;

using P = pair<int, int>;
static const int INF = 10000000, MAXX = 500, MAXY= 500, WALL = 4000000;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int dis[MAXY+2][MAXX+2];
int ma[MAXY+2][MAXX+2] = {};


int main() {
    int h, w, sy, sx, gy, gx;
    cin >> h >> w;
    fill_n(&ma[0][0], 502*502, INF);
    fill_n(&dis[0][0], 502*502, INF);
    queue<P> Q;
    for (int i = 1; i < h+1; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j < w+1; ++j) {
            if (s[j-1] == '#') ma[i][j] = WALL;
            else {
                ma[i][j] = 1;
                if (s[j-1] == 's') {
                    dis[i][j] = 0;
                    sy = i; sx = j;
                    Q.push(make_pair(i, j));
                }
                if (s[j-1] == 'g') {gy = i; gx = j;}
            }
        }
    }
    while (!Q.empty()){
        int y = Q.front().first, x = Q.front().second; Q.pop();
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i], nx = x + dx[i];
            if(ma[ny][nx] != INF && dis[y][x] + ma[ny][nx] < INF && dis[y][x] + ma[ny][nx] < dis[ny][nx]){
                dis[ny][nx] = dis[y][x] + ma[ny][nx];
                Q.push(make_pair(ny, nx));
            }
        }
    }

    cout << (dis[gy][gx] < INF ? "YES\n" : "NO\n");
    return 0;
}
