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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int gx = 0, gy = 0;
int x = 1, y = 1;

void get(char s){
    cout << s << endl;
    cin >> x >> y;
    if(x == gx && y == gy) exit(0);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n+2, vector<int>(m+2, 0));
    auto visited = v, val = v;
    for (int i = 0; i <= n+1; ++i) {
        fill(val[i].begin(),val[i].end(), -1);
    }
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            v[i+1][j+1] = s[j] != '*';
            if(s[j] == 'F'){
                gx = i+1, gy = j+1;
            }
        }
    }
    if(n == 1){
        get('R');
        if(y == 1) {
            for (int i = 0; i < m; ++i) {
                get('L');
            }
        }else {
            for (int i = 0; i < m; ++i) {
                get('R');
            }
        }
    }
    if(m == 1){
        get('D');
        if(x == 1) {
            for (int i = 0; i < n; ++i) {
                get('U');
            }
        }else {
            for (int i = 0; i < n; ++i) {
                get('D');
            }
        }
    }
    int revl = 0, revd = 0;
    if(v[1][2]){
        get('L');
        if(y != 1) revl = 1, get('R');
        while(!v[x+1][y]) get(revl ? 'L' : 'R');
        get('U');
        if(x != 1) revd = 1, get('D');
    }else {
        get('U');
        if(x != 1) revd = 1, get('D');
        while(!v[x][y+1]) get(revd ? 'U' : 'D');
        get('L');
        if(y != 1) revl = 1, get('R');
    }
    array<int, 4> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
    string s = "LRUD";
    queue<pair<int, int>> Q;
    visited[x][y] = 1;
    Q.emplace(x, y);
    while(!Q.empty()){
        int i, j; tie(i, j) = Q.front(); Q.pop();
        for (int k = 0; k < 4; ++k) {
            if(!visited[i+dy[k]][j+dx[k]] && v[i+dy[k]][j+dx[k]]){
                visited[i+dy[k]][j+dx[k]] = 1;
                val[i+dy[k]][j+dx[k]] = k;
                Q.emplace(i+dy[k], j+dx[k]);
            }
        }
    }
    string ans;
    while(gy != y || gx != x){
        int k = val[gx][gy];
        k = (k >= 2 ? k^revd : k^revl);
        ans += s[k];
        int vval = val[gx][gy];
        gx -= dy[vval]; gy -= dx[vval];
    }
    reverse(ans.begin(),ans.end());
    for (auto &&i : ans) {
        get(i);
    }
    return 0;
}