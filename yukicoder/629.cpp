#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

bool IsKadomatsu(int a, int b, int c){
    if(a == b || b == c || c == a) return false;
    return max({a, b, c}) == b || min({a, b, c}) == b;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<pair<int, int>> g;
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        g.emplace_back(a-1, b-1);
        g.emplace_back(b-1, a-1);
    }
    for (int i = 0; i < 2 * m; ++i) {
        for (int j = 0; j < 2 * m; ++j) {
            if(i/2 == j/2 || g[i].second != g[j].first) continue;
            if(!IsKadomatsu(v[g[i].first], v[g[i].second], v[g[j].second])) continue;
            puts("YES");
            return -0;
        }
    }
    puts("NO");
    return 0;
}
