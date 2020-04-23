#include <iostream>
#include <vector>
#include <queue>

using ll = long long;
using namespace std;
using P = pair<int, int>;
static const int INF = 10000000;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int dis[1002][1002];
bool ma[1002][1002] = {};

int main() {
    int h, w, n, t = 0;
    cin >> h >> w >> n;
    P cp[10];
    queue<P> Q;
    fill_n(&dis[0][0], 1002*1002, INF);
    for (int i = 1; i < h+1; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j < w+1; ++j) {
            ma[i][j] = s[j-1] != 'X';
            if(s[j-1] == 'S') cp[0] = make_pair(i, j);
            if('1' <= s[j-1] && s[j-1] <= '9') cp[s[j-1]-'0']= make_pair(i, j);
        }
    }

    for (int i = 0; i < n; ++i) {
        fill_n(&dis[0][0], 1002*1002, INF);
        P st = cp[i], gl = cp[i+1];
        Q.push(st);
        dis[st.first][st.second] = 0;
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
        t += dis[gl.first][gl.second];
    }
    cout << t << "\n";
    return 0;
}
