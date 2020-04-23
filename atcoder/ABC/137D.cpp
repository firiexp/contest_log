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
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        v[i] = {a, b};
    }
    v.emplace_back(INF<int>, 0);
    sort(v.begin(),v.end());
    priority_queue<int> Q;
    int ans = 0;
    int cur = 0;
    for (int i = 1; i <= m; ++i) {
        while(v[cur].first <= i) Q.emplace(v[cur++].second);
        if(!Q.empty()){
            ans += Q.top(); Q.pop();
        }
    }
    cout << ans << "\n";
    return 0;
}