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

int n, m;
array<array<int, 10>, 10> v{};
vector<int> wins;
int dfs(int i) {
    if(i == n) {
        return 1;
    }
    int ans = 0;
    vector<int> w;
    for (int j = 0; j < n; ++j) {
        if(i != j && !v[i][j]) w.emplace_back(j);
    }
    for (int mask = 0; mask < (1<<w.size()); ++mask) {
        if(wins[i] + __builtin_popcount(mask) != n/2) continue;
        for (int j = 0; j < w.size(); ++j) {
            v[i][w[j]] = ((mask>>j)&1)+1;
            v[w[j]][i] = 2-((mask>>j)&1);
            wins[((mask>>j)&1) ? i : w[j]]++;
        }
        ans += dfs(i+1);
        for (int j = 0; j < w.size(); ++j) {
            v[i][w[j]] = v[w[j]][i] = 0;
            wins[((mask>>j)&1) ? i : w[j]]--;
        }
    }
    return ans;
}

int main() {
    while(cin >> n, n){
        cin >> m;
        wins.resize(n);

        for (int i = 0; i < n; ++i) {
            wins[i] = 0;
            for (int j = 0; j < n; ++j) {
                v[i][j] = 0;
            }
        }
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            v[x][y] = 2;
            v[y][x] = 1;
            wins[x]++;
        }

        cout << dfs(0) << "\n";
    }
    return 0;
}