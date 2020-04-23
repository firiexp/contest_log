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
    int n, k;
    cin >> n >> k;
    vector<vector<pair<int, int>>> G(n);
    for (int i = 0; i < n-1; ++i) {
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        G[x-1].emplace_back(y-1, c);
        G[y-1].emplace_back(x-1, c);
    }
    stack<int> s;
    int cnt = 0;
    vector<int> visited(n, 0), num(n);
    vector<int> v;
    s.emplace(0);
    vector<int> dp(n);
    dp[0] = 0;
    while(!s.empty()){
        int a = s.top(); s.pop();
        visited[a]++;
        num[a] = cnt++;
        for (auto &&i : G[a]) {
            if(!visited[i.first]) {
                s.emplace(i.first);
                dp[i.first] = dp[a]^i.second;
            }
        }
    }
    map<int, int> dp2;
    for (int i = 0; i < n; ++i) {
        dp2[dp[i]^k]++;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += dp2[dp[i]];
    }
    cout << (ans-(k == 0)*n)/2  << "\n";
    return 0;
}