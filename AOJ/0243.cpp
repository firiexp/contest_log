#include <iostream>
#include <algorithm>
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

int main() {
    int h, w;
    using A = array<array<char, 12>, 12>;
    while(cin >> w >> h, w){
        A v;
        for (auto &&k : v) fill(k.begin(),k.end(), -1);
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                char c;
                cin >> c;
                if(c == 'R') v[i][j] = 0;
                else if(c == 'G') v[i][j] = 1;
                else v[i][j] = 2;
            }
        }
        int ans = 18;
        array<int, 4> dx{-1, 1, 0, 0}, dy{0, 0, -1, 1};
        vector<pair<int, int>> hist;
        queue<pair<int, int>> Q;
        auto dfs = [&](int dep, A a, int prv, auto &&f) -> void {
            if(dep >= ans) return;
            for (int to = 0; to < 3; ++to) {
                if(a[1][1] == to) continue;
                A b = a;
                int cnt = 0;
                Q.emplace(1, 1);
                b[1][1] = to;
                while(!Q.empty()){
                    int y, x; tie(y, x) = Q.front(); Q.pop();
                    cnt++;
                    for (int k = 0; k < 4; ++k) {
                        if(b[y+dy[k]][x+dx[k]] == a[1][1]){
                            b[y+dy[k]][x+dx[k]] = to;
                            Q.emplace(y+dy[k], x+dx[k]);
                        }
                    }
                }
                if(cnt == h*w) ans = min(ans, dep);
                else if(prv < cnt) f(dep+1, b, cnt, f);
            }
        };
        dfs(0, v, 0, dfs);
        cout << ans << "\n";
    }


    return 0;
}

