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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        G[a-1].emplace_back(b-1);
        G[b-1].emplace_back(a-1);
    }
    deque<int> Q;
    vector<int> num(n);
    {
        stack<int> s;
        int cnt = 0;
        vector<int> visited(n, 0);
        s.emplace(0);
        while(!s.empty()){
            int a = s.top(); s.pop();
            visited[a]++;
            num[a] = cnt++;
            Q.emplace_front(a);
            for (auto &&i : G[a]) {
                if(!visited[i]) s.emplace(i);
            }
        }
    }
    vector<int> dp(n, 0);
    while(!Q.empty()){
        int i = Q.front(); Q.pop_front();
        for (auto &&j : G[i]) {
            if(num[i] < num[j]){
                dp[i] ^= dp[j]+1;
            }
        }
    }
    puts(dp[0] ? "Alice" : "Bob");
    return 0;
}
