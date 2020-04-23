#include <iostream>
#include <queue>

using ll = long long;
using namespace std;
static const int INF = 100000000;
using P = pair<int, int>;

int main() {
    int h, w;
    char c;
    int gx = INF, gy = INF;
    queue<P> Q;
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    cin >> h >> w;
    char city[501][501];
    int di[501][501];
    for (int i = 0; i <= h; ++i) {
        for (int j = 0; j <= w; ++j) {
            di[i][j] = INF;
        }
    }
    for (int i = 0; i < h; ++i) {
        string x;
        cin >> x;
        for (int j = 0; j < w; ++j) {
            city[i][j] = x[j];
            if(x[j] == 's') {
                di[i][j] = 0;
                Q.push(P(i,j));
            }
            if(x[j] == 'g') {gx = i; gy = j;}
        }

    }
    while(!Q.empty()){
        P p = Q.front(); Q.pop();
        if (p.first == gx && p.second == gy){
            cout << "Yes" << "\n";
            return 0;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(0 <= nx && nx < h && 0 <= ny && ny < w && city[nx][ny] != '#' &&
            di[nx][ny] == INF){
               Q.push(P(nx, ny));
               di[nx][ny] = di[p.first][p.second] + 1;
            }
        }
    }
    if(di[gx][gy] >= INF) {
        cout << "No" << "\n";
    }else cout << "Yes" << "\n";
    return 0;
}
