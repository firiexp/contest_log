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

int lcm(int i, int j){
    return i/__gcd(i, j)*j;
}

int main() {
    int n;
    while(cin >> n){
        vector<int> L(n), R(n), S(n), T(n);
        vector<vector<int>> G(n);
        vector<int> dp(n), indeg(n);
        for (int i = 0; i < n; ++i) {
            int p, q, r, b;
            scanf("%d %d %d %d", &p, &q, &r, &b);
            r--; b--;
            L[i] = p, R[i] = q, S[i] = r, T[i] = b;
            if(r < 0 && b < 0){
                dp[i] = (p+q)/__gcd(p, q);
            } else {
                if(r >= 0) G[i].emplace_back(r), indeg[r]++;
                if(b >= 0) G[i].emplace_back(b), indeg[b]++;
            }
        }
        deque<int> Q;
        stack<int> s;
        int cnt = 0;
        int x = min_element(indeg.begin(),indeg.end()) - indeg.begin();
        vector<int> visited(n, 0), num(n);
        s.emplace(x);
        while(!s.empty()){
            int a = s.top(); s.pop();
            visited[a]++;
            num[a] = cnt++;
            if(!dp[a]) Q.emplace_front(a);
            for (auto &&i : G[a]) {
                if(!visited[i]) s.emplace(i);
            }
        }
        while(!Q.empty()){
            int i = Q.front(); Q.pop_front();
            if(S[i] < 0){
                int j = T[i];
                dp[i] = lcm(dp[j]*R[i], L[i])/L[i]+ lcm(dp[j]*R[i], L[i])/R[i];
            }else if(T[i] < 0){
                int j = S[i];
                dp[i] = lcm(dp[j]*L[i], R[i])/L[i]+ lcm(dp[j]*L[i], R[i])/R[i];
            }else {
                dp[i] = lcm(dp[S[i]]*L[i], dp[T[i]]*R[i])/L[i]+lcm(dp[S[i]]*L[i], dp[T[i]]*R[i])/R[i];
            }
        }
        cout << dp[x] << "\n";
    }

    return 0;
}