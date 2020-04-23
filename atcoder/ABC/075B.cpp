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
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1}, dy[8] = {1,1,1,0,0,-1,-1,-1};


int main() {
    u32 h, w;
    cin >> h >> w;
    vector<vector<char>> v(h+2, vector<char>(w+2, '.'));
    for (int i = 1; i <= h; ++i) {
        string k;
        cin >> k;
        for (int j = 1; j <= w; ++j) {
            v[i][j] = k[j-1];
        }
    }
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if(v[i][j] == '#') continue;
            int cnt = 0;
            for (int k = 0; k < 8; ++k) {
                if(v[i+dx[k]][j+dy[k]] == '#') cnt++;
            }
            v[i][j] = char('0' + cnt);
        }
    }
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            cout << v[i][j];
        }
        cout << "\n";
    }
    return 0;
}
