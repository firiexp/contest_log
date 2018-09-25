#include <iostream>
#include <queue>
#include <algorithm>

using ll = long long;
using namespace std;
using p = pair<int, int>;
static const int INF = 10000;

int main() {
    string s;
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    int dis[10][10], dis2[10][10];
    char mp[10][10], mp2[10][10];
    queue<p> q1, q2;
    for (int i = 0; i < 10; ++i) {
        cin >> s;
        for (int j = 0; j < 10; ++j) {
            mp[i][j]=s[j];
            q1.push({i, j});
            dis[i][j]= INF;
        }
    }
    while (!q1.empty()){
        bool flag = true;
        p fill = q1.front(); q1.pop();
        copy_n(&mp[0][0], 100, &mp2[0][0]);
        copy_n(&dis[0][0], 100, &dis2[0][0]);
        dis2[fill.first][fill.second] = 0;
        mp2[fill.first][fill.second] = 'o';
        q2.push(fill);
        while (!q2.empty()){
            p q = q2.front(); q2.pop();
            for (int i = 0; i < 4; ++i) {
                p qq = make_pair(q.first+dx[i],q.second+dy[i]);
                if(0<= qq.first && qq.first < 10 && 0<= qq.second && qq.second < 10 &&
                   dis2[qq.first][qq.second] >= INF && mp2[qq.first][qq.second] == 'o'){
                    dis2[qq.first][qq.second] = dis2[q.first][q.second] + 1;
                    q2.push(qq);
                }
            }
        }
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if(mp2[i][j] == 'o' && dis2[i][j] >= INF){
                    flag = false;
                }
            }
        }

        if(flag) {cout << "YES\n"; return 0;}
    }
    cout << "NO\n";
    return 0;
}
