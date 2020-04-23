#include <iostream>
#include <algorithm>
#include <vector>

using ll = long long;
using namespace std;
static const int INF = 1000000007;
using P = pair<int, int>;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};



int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> m(52, vector<int> (52, INF));
    for (int i = 1; i <= h; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= w; ++j) {
            if(s[j-1] == '#') m[i][j] = 1;
            else m[i][j] = 2;
        }
    }
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if(m[i][j] <= 1){
                for (int k = 0; k < 4; ++k) {
                    if(m[i+dx[k]][j+dy[k]] <= 1){
                        m[i][j] = 0; m[i+dx[k]][j+dy[k]] = 0;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if(m[i][j] == 1) {
                cout << "No" << "\n";
                return 0;
            }
        }
    }
    cout << "Yes" << "\n";
    return 0;
}
