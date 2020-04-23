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
    vector<vector<int>> v(h+2, vector<int> (w+2, 1));
    queue<pair<int, int>> Q;
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            v[i+1][j+1] = (s[j] == '#');
            if(v[i+1][j+1]) Q.emplace(i+1, j+1);
        }
    }
    auto visited = v;
    int di[] {1, -1, 0, 0}, dj[]{0, 0, -1, 1};
    int ans = 1;
    while(!Q.empty()){
        int p, q; tie(p, q) = Q.front(); Q.pop();
        for (int i = 0; i < 4; ++i) {
            if(!v[p+di[i]][q+dj[i]]){
                v[p+di[i]][q+dj[i]] = v[p][q]+1;
                ans = max(ans, v[p+di[i]][q+dj[i]]);
                Q.emplace(p+di[i], q+dj[i]);
            }
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            ans = max(ans, v[i+1][j+1]);
        }
    }
    cout << ans-1 << "\n";
    return 0;
}