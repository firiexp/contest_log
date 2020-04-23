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
    vector<vector<int>> G(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b; scanf("%d %d", &a, &b); a--; b--;
        G[a].emplace_back(b); G[b].emplace_back(a);
    }
    deque<int> Q;
    stack<int> s;
    int cnt = 0;
    vector<int> visited(n, 0), num(n);
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
    vector<int> dp(n);
    for (int i = 0; i < m; ++i) {
        int a; scanf("%d", &a);
        dp[a-1]++;
    }
    int k = -1;
    for (int xx = 0; xx < n; ++xx) {
        int i = Q.front(); Q.pop_front();
        if(!(~k)) {
            for (auto &&j : G[i]) {
                if(num[i] < num[j]) dp[i] += dp[j];
            }
            if(dp[i] == m) k = i;
        }
    }
    int l = -1, r = -1;
    for (auto &&i : G[k]) {
        if(dp[i]){
            if(~r && ~l){
                puts("trumpet");
                return 0;
            }else if(~l){
                r = i;
            }else {
                l = i;
            }
        }
    }
    while(~l){
        int newl = -1;
        for (auto &&i : G[l]) {
            if(num[l] < num[i] && dp[i]){
                if(~newl){
                    puts("trumpet");
                    return 0;
                }else newl = i;
            }
        }
        if(!(~newl)) break;
        l = newl;
    }
    while(~r){
        int newr = -1;
        for (auto &&i : G[r]) {
            if(num[r] < num[i] && dp[i]){
                if(~newr){
                    puts("trumpet");
                    return 0;
                }else newr = i;
            }
        }
        if(!(~newr)) break;
        r = newr;
    }
    puts("Yes");
    return 0;
}