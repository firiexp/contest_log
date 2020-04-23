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
    int n, m;
    cin >> n >> m;
    if(m%2){
        puts("-1");
        return 0;
    }
    vector<int> deg(n);
    vector<vector<int>> G(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        deg[a]++;
        G[a].emplace_back(b);
    }
    for (int i = 0; i < n; ++i) {
        if(deg[i]){

        }
    }
    return 0;
}