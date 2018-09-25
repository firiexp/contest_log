#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;
using P = pair<int, int>;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> v(h+2, vector<char>(w+2, '.'));
    for (int i = 1; i <= h; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= w; ++j) {
            v[i][j]=s[j-1];
        }
    }
    int x = 0, y = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if(v[i][j] == '#' && x*y == 0) {
                x = i, y = j;
                break;
            }
        }
    }
    int dx[2] = {0, 1}, dy[2] = {1, 0};
    queue<P> Q;
    Q.emplace(x, y);
    while(!Q.empty()){
        P p = Q.front(); Q.pop();
        v[p.first][p.second] = '.';
        for (int i = 0; i < 2; ++i) {
            if(v[p.first+dx[i]][p.second+dy[i]]== '#'){
                Q.emplace(p.first+dx[i], p.second+dy[i]);
                break;
            }
        }
    }
    cout << "\n";
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if(v[i][j] == '#') {
                cout << "Impossible" << "\n";
                return 0;
            }
        }
    }
    cout << "Possible" << "\n";
    return 0;
}
