#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int h, w;
    cin >> h >> w;
    using P = pair<int, int>;
    P a, b;
    vector<vector<int>> v(h+2, vector<int> (w+2, 0));
    queue<P> Q, QQ;
    vector<vector<int>> dist1(h+2, vector<int> (w+2, MOD));

    auto dist2 = dist1;

    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            v[i+1][j+1] = (s[j] != '#');
            if(s[j] == '@') {
                a = {i + 1, j + 1};
                dist1[i+1][j+1] = 0;
            }
            else if(s[j] == '%') b = {i+1, j+1};
            else if(s[j] == '$') {
                Q.emplace(i+1, j+1);
                dist2[i+1][j+1] = 0;
            }
        }
    }
    array<int, 4> di{0, 0, -1, 1}, dj{1, -1, 0, 0};

    QQ.emplace(a);
    while(!QQ.empty()){
        int i, j;
        tie(i, j) = QQ.front(); QQ.pop();
        for (int k = 0; k < 4; ++k) {
            if(v[i+di[k]][j+dj[k]] && dist1[i+di[k]][j+dj[k]] > dist1[i][j]+1){
                dist1[i+di[k]][j+dj[k]] = dist1[i][j]+1;
                QQ.emplace(i+di[k], j+dj[k]);
            }
        }
    }
    while(!Q.empty()){
        int i, j;
        tie(i, j) = Q.front(); Q.pop();
        for (int k = 0; k < 4; ++k) {
            if(v[i+di[k]][j+dj[k]] && dist2[i+di[k]][j+dj[k]] > dist2[i][j]+1){
                dist2[i+di[k]][j+dj[k]] = dist2[i][j]+1;
                Q.emplace(i+di[k], j+dj[k]);
            }
        }
    }
    puts((dist2[b.first][b.second] > dist1[b.first][b.second]) ? "Yes" : "No");
    return 0;
}