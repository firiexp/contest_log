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
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int> (n-1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-1; ++j) {
            scanf("%d", &v[i][j]);
            v[i][j]--;
        }
    }
    auto f = [&n](int i, int j){ return i*n+j; };
    int m = n*(n-1)/2;
    vector<vector<int>> G(n*n);
    vector<int> deg(n*n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-2; ++j) {
            int l = min(i, v[i][j]), r = max(i, v[i][j]);
            int ll = min(i, v[i][j+1]), rr = max(i, v[i][j+1]);
            G[f(l, r)].emplace_back(f(ll, rr));
            deg[f(ll, rr)]++;
        }
    }
    vector<int> dp(n*n, 1);
    queue<int> Q;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if(!deg[f(i, j)]){
                ans++;
                Q.emplace(f(i, j));
            }
        }
    }

    while(!Q.empty()){
        int i = Q.front(); Q.pop();

        for (auto &&j : G[i]) {
            dp[j] = max(dp[j], dp[i]+1);
            deg[j]--;
            if(deg[j] == 0) {
                Q.emplace(j);
                ans++;
            }
        }
    }
    if(ans != n*(n-1)/2){
        puts("-1");
    }else {
        cout << *max_element(dp.begin(),dp.end()) << "\n";
    }
    return 0;
}