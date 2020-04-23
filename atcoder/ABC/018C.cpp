#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;


int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};



int main() {
    int r, c, k;
    cin >> r >> c >> k;
    vector<string> v;
    vector<vector<int>> v2(r, vector<int>(c, INF<int>));
    for (int i = 0; i < r; ++i) {
        string s;
        cin >> s;
        v.emplace_back(s);
    }
    queue<pair<int, int>> Q;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if(v[i][j] == 'x'){
                v2[i][j] = 0;
                Q.emplace(i, j);
            }
        }
    }
    while(!Q.empty()){
        int x, y;
        tie(y, x)= Q.front(); Q.pop();
        for (int i = 0; i < 4; ++i) {
            int q = y+dy[i], p = x+dx[i];
            if(0 <= q && q < r && 0 <= p && p < c)
                if(v2[q][p] > v2[y][x] + 1){
                v2[q][p] = v2[y][x]+1;
                Q.emplace(q, p);
            }
        }
    }
    int ans = 0;
    for (int i = k-1; i < r-k+1; ++i) {
        for (int j = k-1; j < c-k+1; ++j) {
            if(v2[i][j] >= k) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
