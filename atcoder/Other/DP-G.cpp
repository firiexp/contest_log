#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;



int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n, 0);
    vector<vector<int>> G(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        G[x-1].emplace_back(y-1);
        p[y-1]++;
    }
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        if(p[i] == 0) st.emplace(i);
    }
    queue<int> Q;
    while(!st.empty()){
        int i = st.top(); st.pop();
        Q.emplace(i);
        for (auto &&j : G[i]) {
            p[j]--;
            if(p[j] == 0) st.push(j);
        }
    }
    vector<int> dp(n, 0);
    int ans = 0;
    while(!Q.empty()){
        for (auto &&i : G[Q.front()]) {
            dp[i] = max(dp[i], dp[Q.front()]+1);
        }
        Q.pop();
    }
    cout << (*max_element(dp.begin(), dp.end())) << "\n";
    return 0;
}
