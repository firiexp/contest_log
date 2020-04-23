#include <iostream>
#include <vector>
#include <queue>

using ll = long long;
using namespace std;
using P = pair<int, int>;
static const int INF = 10000000, MAXX = 50, MAXY=50;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int dis[MAXY+2][MAXX+2];
bool ma[MAXY+2][MAXX+2] = {};

int main() {
    int h, w, c = 0;
    cin >> h >> w;
    queue<P> Q;
    fill_n(&dis[0][0], MAXX*MAXY, INF);
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            ma[i+1][j+1] = s[j] != '#';
            if(s[j] != '#') c++;
        }
    }
    Q.push(make_pair(1, 1));
    dis[1][1] = 1;
    while(!Q.empty()){
        int y = Q.front().first, x = Q.front().second; Q.pop();
        for (int j = 0; j < 4; ++j) {
            int ny = y + dy[j], nx = x + dx[j];
            if(dis[ny][nx] == INF && ma[ny][nx]){
                dis[ny][nx] = dis[y][x] + 1;
                Q.push(make_pair(ny, nx));
            }
        }
    }

    cout << (dis[h][w] == INF ? -1 : c-dis[h][w]) << "\n";
    return 0;
}
