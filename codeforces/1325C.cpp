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

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> G(n);
    vector<int> ans(n-1, -1);
    vector<int> deg(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        deg[a]++; deg[b]++;
        G[a].emplace_back(b, i);
        G[b].emplace_back(a, i);
    }
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if(deg[i] > 2){
            for (int j = 0; j < 3; ++j) {
                ans[G[i][j].second] = j;
            }
            cur += 3;
            break;
        }
    }
    for (int i = 0; i < n-1; ++i) {
        if(ans[i] == -1) ans[i] = cur++;
        printf("%d\n", ans[i]);
    }
    return 0;
}