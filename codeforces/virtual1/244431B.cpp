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
    vector<int> v(n);
    map<int, int> x;
    for (auto &&i : v) scanf("%d", &i);
    for (int i = 0; i < m; ++i) {
        int y; scanf("%d", &y);
        x[y]++;
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if(x[v[i]]) ans.emplace_back(v[i]);
    }
    for (int i = 0; i < ans.size(); ++i) {
        if(i) cout << " ";
        cout << ans[i];
    }
    puts("");
    return 0;
}